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
void zad2_2(int start1, int end1, int start2, int end2);
#define INFTY INT_MAX
int** M1, *nodes, *nodes3;
int N;



using Edge = int; // ����� - ����� �����, �����������, ���� ����
using Vertex = std::vector<Edge>; // ������� - ����� ����
using Graph = std::vector<Vertex>; // ���� - ����� ������
Graph g1;

std::vector<bool> was; // ���������� ������� (��� ������ ���������)

using node2 = int;
using nodes2 = std::vector<node2>; // ���������� ������� (������������� ����� ��� �������)
nodes2 nodes_list;

using namespace std;
queue <int> Q;
int st;





// ����������� �������������� �������
///////////////////////////////////////////////////
#define QMAX 1000
struct queue_sam {
	int qu[QMAX];
	int rear, frnt;
};

void init(struct queue_sam* q) { // ������������� �������
	q->frnt = 1;
	q->rear = 0;
	return;
}

void insert(struct queue_sam* q, int x) { // ���������� � �������
	if (q->rear < QMAX - 1) {
		q->rear++;
		q->qu[q->rear] = x;
	}
	else
		printf("������� �����!\n");
	return;
}

int isempty(struct queue_sam* q) { // ��������, ����� �� �������
	if (q->rear < q->frnt)    return 1;
	else  return 0;
}

int remove(struct queue_sam* q) { // �������� �� �������
	int x;
	if (isempty(q) == 1) {
		printf("������� �����!\n");
		return(0);
	}
	x = q->qu[q->frnt];
	q->frnt++;
	return x;
}
///////////////////////////////////////////////////









void main() {

	zad1();


	for (int i = 0; i < N; i++) // ������� ��� ������� ����� 0
		nodes[i] = -1;
	printf(" \n");

	printf("\n �������� ������� ��� ������\n ");
	scanf("%d", &st);
	st--;



	printf("\n 1.2. ����� � ������ ������� ��������� ����� ����� queue\n ");
	clock_t start1 = clock();
	zad1_2(st, N);
	clock_t end1 = clock();

	printf("\n\n 1.3. ����� � ������ ������ ��������� ����� ����� queue\n ");
	was.resize(N);
	for (int i = 0; i < N; i++) {
		was[i] = 0; // ������� ��� ������� ����� 0 - ������� ��� �� ����� �� ����
	}

	zad1_3(st);


	printf("\n\n 2.1. ����� � ������ ������� ��������� ����� ������������� �������������� �������\n ");
	for (int i = 0; i < N; i++) // ������� ��� ������� ����� 0
		nodes3[i] = 0;
	clock_t start2 = clock();
	zad2_1(st, N);
	clock_t end2 = clock();

	zad2_2(start1, end1, start2, end2);
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
	int r;
	Q.push(st);

	nodes[st] = 0;
	int st2 = st;

	while (!Q.empty())
	{
		st = Q.front();
		Q.pop();
		printf("%d(%d) ", st + 1, nodes[st] + 1);
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
	was[st] = true;

	while (!q.empty()) {
		int cur = q.front();  //��������� �� ������� ������� �������
		q.pop();

		//����� ������ ���� ��������� ������� �������.
		printf("%d ", cur + 1);

		for (int sosed : g1[cur]) {    //��������� ���� ������������ �������.
			if (!was[sosed]) {
				q.push(sosed);
				was[sosed] = true;
			}
		}
	}
}

void zad2_1(int st, int N)
{
	struct queue_sam* q; // �������������� ��������� �� ��������� ���� �������
	q = (queue_sam*)malloc(sizeof(queue_sam)); // �������� ������
	init(q); // ��������������

	int r;
	insert(q, st); // ������� �������� ������� � ���� �������


	nodes3[st] = 1;
	while (isempty(q) != 1) // ���� ������� �� �����
	{
		st = remove(q); // ������� � ������� ������� �� ����� �������
		printf("%d ", st + 1);
		for (r = 0; r < N; r++)
			if ((M1[st][r] != 0) && (nodes3[r] == 0)) // ����� ���������� � ������� �� ��������
			{
				insert(q, r); // ������� ��������� �������
				nodes3[r] = 1;
			}
	}
}

void zad2_2(int start1, int end1, int start2, int end2)
{
	printf("\n\n���������� ������ ������� ������������ ������ 'queue': %.2f ms\n", difftime(end1, start1));

	printf("\n���������� ������ �������, �������������� ��������������: %.2f ms\n", difftime(end2, start2));
}


