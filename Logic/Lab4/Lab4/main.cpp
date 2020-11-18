#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
#include <iostream> 
#include <vector>

#include <stack> // ����
#include <string>
#include <limits>


void zad1();
void zad1_2(int st, int N);
void zad1_3(int v);
void zad2(int st);

#define INFTY INT_MAX
int** M1, *nodes;
int N;

using Edge = int; // ����� - ����� �����, �����������, ���� ����
using Vertex = std::vector<Edge>; // ������� - ����� ����
using Graph = std::vector<Vertex>; // ���� - ����� ������
Graph g1;

std::vector<bool> was; // ���������� ������� (��� ������ ���������)

using node2 = int;
using nodes2 = std::vector<node2>; // ���������� ������� (������������� ����� ��� �������)
nodes2 nodes_list;



void main() {

	zad1();


	for (int i = 0; i < N; i++) // ������� ��� ������� ����� 0
		nodes[i] = 0;
	printf(" \n");
	int st;
	printf("\n �������� ������� ��� ������\n ");
	scanf("%d", &st);
	st--;

	
	
	printf("\n 1.2. ����������� ����� � ������� ������� ���������\n ");
	zad1_2(st, N);

	
	
	printf("\n\n 1.3. ����������� ����� � ������� ������ ���������\n ");
	was.resize(N);
	for (int i = 0; i < N; i++) {
		was[i] = 0; // ������� ��� ������� ����� 0 - ������� ��� �� ����� �� ����
	}
	zad1_3(st); // ��������� ����� � ������� �� ��������� �������, ������� �� �����
	

	zad2(st);

	getch();



}

void zad1() {

	setlocale(LC_ALL, "russian");

	printf("\n ������� ������ ������� N*N: ");
	scanf("%d", &N);

	M1 = (int**)malloc(N * sizeof(int *));
	for (int i = 0; i < N; i++)
	{
		M1[i] = (int*)malloc(N * sizeof(int));
	}
	nodes = (int*)malloc(N * sizeof(int));

	srand(time(NULL));
	int ch = 0;
	for (int i = 0; i < N; i++) // ��������� ������� M1
	{
		M1[i][i] = 0;

		for (int j = i + 1; j < N; j++)
		{

			ch = rand() % 10;
			if (ch < 6)
				M1[i][j] = 0;
			else
				M1[i][j] = 1;

			M1[j][i] = M1[i][j];


		}
	}

	printf("\n 1. ����� ��������������� ������� ��������� ����������������� ������\n ");

	for (int i = 0; i < N; i++) { // ����� ������ ���������

		printf("\n ");

		for (int j = 0; j < N; j++) {
			printf("%d", M1[i][j]);
		}


	}

	g1.resize(N); // ������ ������ �����
	for (int i = 0; i < N; i++) // ���������� ���������������� ���������
	{
		for (int j = 0; j < N; j++)
		{
			if (M1[i][j] == 1)
				g1[i].push_back(j);
		}
	}

	printf("\n\n");

	for (int i = 0; i < g1.size(); i++) // ����� ������
	{
		std::cout << "  " << i + 1 << " : ";
		for (int j = 0; j < g1[i].size(); j++)
		{
			std::cout << g1[i][j] + 1 << " ";
		}

		std::cout << "\n";
	}

	_getch();
}




void zad1_2(int st, int N)
{
	int r;


	printf("%d ", st + 1);
	nodes[st] = 1;
	for (r = 0; r < N; r++)
		if ((M1[st][r] != 0) && (nodes[r] == 0)) // ����� ���������� � ������� �� ��������
			zad1_2(r, N);

}

void zad1_3(int v) {
	if (was[v]) { // ���� �� ���� � ������ �������, �� ������ �� ���
		return;
	}
	was[v] = 1; // ������� ��� ��� ���� � ���� �������
	printf("%d ", v + 1);
	for (int i : g1[v]) { // ����, ���������� �� ���������
		zad1_3(i); // ��������� ����� ����� �� ������� ������
	}
}

void zad2(int st) {

	setlocale(LC_ALL, "russian");

	std::stack <int> Stack; //�������� ����� ����� � �������, ��������� ����
	
	nodes_list.resize(N);  // ������ ������ �����

	printf("\n\n 2*. ������������� ����� � ������� ������� ���������\n ");

	for (int i = 0; i < N; i++) 
		nodes_list[i] = 0; // ������� ��� ������� ����� 0
	
	Stack.push(st); // �������� � ������� �������� �������
	nodes_list[st] = 1;

	while (!Stack.empty()) // ���� ���� �� ����
	{ 
		int node = Stack.top(); // ��������� �������
		Stack.pop();

		/*if (nodes_list[node] == 1) 
			continue; */

		//nodes_list[node] = 1; // �������� �� ��� ����������

			for (int j = (N-1); j >= 0; j--) // ��������� ��� ��� ��� ������� �������
			{ 
				if (M1[node][j] == 1 && nodes_list[j] != 1) // ���� ������� ������� � �� ����������
				{ 
					Stack.push(j); // ��������� �� � c���
					nodes_list[j] = 1;
				}
			}
			std::cout << node + 1 << " "; // ������� ����� �������
			
		}


}

	