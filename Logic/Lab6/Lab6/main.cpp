#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
#include <iostream> 
#include <vector>
#include <time.h>

#include <stack> // ����
#include <string>
#include <limits>
#include <queue> 

void zad1();
void zad1_2(int st, int N);
void zad1_3(int st);
void zad2_1(int st, int N);
void zad2_2(int st);
void zad2_3(int start1, int start2, int start3, int start4, int end1, int end2, int end3, int end4, int N);
#define INFTY INT_MAX
int** M1, *nodes, *nodes3;
int N;



using Edge = int; // ����� - ����� �����, �����������, ���� ����
using Vertex = std::vector<Edge>; // ������� - ����� ����
using Graph = std::vector<Vertex>; // ���� - ����� ������
Graph g1;

std::vector<int> was; // ���������� ������� (��� ������ ���������)

using node2 = int;
using nodes2 = std::vector<node2>; // ���������� ������� (������������� ����� ��� �������)
nodes2 nodes_list;

using namespace std;
queue <int> Q;
int st;






void main() {

	zad1();


	for (int i = 0; i < N; i++) // ������� ��� ������� ����� -1
		nodes[i] = -1;
	printf(" \n");

	printf("\n �������� ������� ��� ������\n ");
	scanf("%d", &st);
	st--;



	printf("\n 1.2. ����� ���������� �� ������ ������ � ������ ������� ���������\n ");
	for (int i = 0; i < N; i++) // ������� ��� ������� ����� -1
		nodes[i] = -1;
	clock_t start1 = clock();
	zad1_2(st, N);
	clock_t end1 = clock();

	printf("\n\n 1.3 ����� ���������� �� ������ ������ � ������ ������ ���������\n ");
	was.resize(N);
	for (int i = 0; i < N; i++) {
		was[i] = -1; // ������� ��� ������� ����� -1
	}
	clock_t start2 = clock();
	zad1_3(st);
	clock_t end2 = clock();

	printf("\n\n 2.1 ����� ���������� �� ������ ������ � ������� ������� ���������\n ");
	for (int i = 0; i < N; i++) // ������� ��� ������� ����� -1
		nodes[i] = -1;
	nodes[st] = 0;
	clock_t start3 = clock();
	zad2_1(st, N);
	clock_t end3 = clock();


	printf("\n\n 2.2 ����� ���������� �� ������ ������ � ������� ������ ���������\n ");
	for (int i = 0; i < N; i++) // ������� ��� ������� ����� -1
		nodes[i] = -1;
	nodes[st] = 0;
	clock_t start4 = clock();
	zad2_2(st);
	clock_t end4 = clock();
	
	zad2_3(start1, start2, start3, start4, end1, end2, end3, end4, N);

	_getch();

}

void zad1() {

	setlocale(LC_ALL, "russian");

	printf("\n ������� ������ ������� N*N: ");
	scanf("%d", &N);

	M1 = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		M1[i] = (int*)malloc(N * sizeof(int));
	}

	nodes = (int*)malloc(N * sizeof(int));
	nodes3 = (int*)malloc(N * sizeof(int));

	srand(time(NULL));
	int ch = 0;
	for (int i = 0; i < N; i++) // ��������� ������� M1
	{
		M1[i][i] = 0;

		for (int j = i + 1; j < N; j++)
		{

			ch = rand() % 10;
			if (ch < 7)
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
	int r, i = 0;
	Q.push(st);

	nodes[st] = 0;
	
	while (!Q.empty())
	{
		st = Q.front();
		Q.pop();


		printf("%d(%d) ", st + 1, nodes[st]);
		

		for (r = 0; r < N; r++)
			if ((M1[st][r] != 0) && (nodes[r] == -1)) // ����� ���������� � ������� �� ��������
			{
				Q.push(r);
				nodes[r] = nodes[st] + 1;

			}
	}


}


void zad1_3(int st) {
	queue<int> q;
	q.push(st);  //� �������� ��������� ������� ���������� ��������
	
	was[st] = 0;

	while (!q.empty()) {
		int st = q.front();  //��������� �� ������� ������� �������
		q.pop();

		//����� ������ ���� ��������� ������� �������.
		printf("%d(%d) ", st + 1, was[st]);

		for (int sosed : g1[st]) {    //��������� ���� ������������ �������.
			if (was[sosed] == -1) {
				q.push(sosed);
				was[sosed] = was[st] + 1;
			}
		}
	}
}


void zad2_1(int st, int N)
{
	int r;

	printf("%d(%d) ", st + 1, nodes[st]);

	for (r = 0; r < N; r++)
	{
		if ((M1[st][r] != 0) && (nodes[r] == -1)) // ����� ���������� � ������� �� ��������
		{
			nodes[r] = nodes[st] + 1;
			zad2_1(r, N);
		}

	}
}
void zad2_2(int st) {

	printf("%d(%d) ", st + 1, nodes[st]);
	for (int i : g1[st]) { // ����, ���������� �� ���������
		if (nodes[i] == -1)
		{
			nodes[i] = nodes[st] + 1;
			zad2_2(i); // ��������� ����� ����� �� ������� ������
		}
	}
}
void zad2_3(int start1, int start2, int start3, int start4, int end1, int end2, int end3, int end4, int N)
{
	printf("\n\n������ �������� ������� - %d X %d", N, N);
	printf("\n\n���������� ������ <����� ���������� - ����� � ������ ������� ���������>: %.2f ms", difftime(end1, start1));
	printf("\n���������� ������ <����� ���������� - ����� � ������ ������ ���������>: %.2f ms", difftime(end2, start2));
	printf("\n���������� ������ <����� ���������� - ����� � ������� ������� ���������>: %.2f ms", difftime(end3, start3));
	printf("\n���������� ������ <����� ���������� - ����� � ������� ������ ���������>: %.2f ms", difftime(end4, start4));
}