#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
#include <iostream> 
#include <fstream>
#include <iomanip>
#include <vector>
#include <time.h>

#include <stack> // ����
#include <string>
#include <limits>
#include <queue> 

void generation();


#define INFTY INT_MAX
int** M1, **M2;
int N;
void bellman_ford();

using namespace std;
vector <int> nodes; // ������ ����������
int st = 0; // ��������� �������


#define inf 100000
using namespace std;
struct Edges {
	int u, v, w;
};
const int Vmax = 1000;
const int Emax = Vmax * (Vmax - 1) / 2;
int i, j, n, e, start;

Edges edge[Emax]; // ����� ����


//������� �������

void main()
{
	setlocale(LC_ALL, "Rus");
	int w, c;
	
	
	ofstream fout;

	fout.open("../../bellman_ford.txt", ios::app);

	if (!fout.is_open())
	{
		cout << "\n ������ �������� �����";
		_Exit(EXIT_SUCCESS);
	}

	fout << endl << endl << endl;

	cout << "\n ������� ������ ���� �������?";
	cout << "\n 1 - ��";
	cout << "\n 2 - ��� (��������� ���������)";
	c = _getch();

	if (c == 49)
	{
		cout << "\n\n ���������� ������ > "; cin >> N;
		nodes.resize(N);

		M1 = (int**)malloc(N * sizeof(int*));
		for (int i = 0; i < N; i++)
		{
			M1[i] = (int*)malloc(N * sizeof(int));
		}

		e = 0;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
			{
				cout << " ��� " << i + 1 << " -> " << j + 1 << " = "; cin >> w;
				M1[i][j] = 0;
				if (w != 0)
				{
					edge[e].v = i;
					edge[e].u = j;
					edge[e].w = w;
					M1[i][j] = w;
					e++;
				}
			}
		cout << "\n";
	}
		
	else
	{
		cout << "\n";
		generation();
		e = 0;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
			{
			
				if (M1[i][j] != 0)
				{
					edge[e].v = i;
					edge[e].u = j;
					edge[e].w = M1[i][j];
					e++;
				}
			}
	}

	///// ����� ������� ���������
	printf("    ");
	fout << "    ";

	for (int i = 0; i < N; i++)
	{
		printf("[%d] ", i + 1);
		fout << "[" << i + 1 << "] ";

	}
	for (int i = 0; i < N; i++)
	{
		printf("\n[%d]", i + 1);
		fout << "\n[" << i + 1 << "]";

		for (int j = 0; j < N; j++)
		{
			if ((i + 1) < 10)
			{
				if (j < 10)
				{
					printf("%3d ", M1[i][j]);
					fout << setw(3) << M1[i][j] << " ";
	
				}
				else
				{ 
					printf(" %3d ", M1[i][j]);
					fout << " " << setw(3) << M1[i][j] << " ";
				}
			}

			else if ((i + 1) < 100)
			{
				if (j == 0)
				{
					printf(" %d", M1[i][j]);
					fout << " " << M1[i][j];
				}

				else if (j < 10)
				{
					printf("   %d", M1[i][j]);
					fout << "   " << M1[i][j];
				}
				
				else
				{
					printf("    %d", M1[i][j]);
					fout << "    " << M1[i][j];
				}

			}

		}

	}
	/////
	
	cout << "\n\n ��������� ������� > "; cin >> st;
	fout << "\n\n ��������� ������� > " << st; 
	st--;
	cout << "\n ������ ���������� �����:";
	fout << "\n ������ ���������� �����:";
	fout.close();

	bellman_ford();
	
	getch();
}

void generation() // ��������� ���������� ������
{

	int naprav = 0;
	char c;

	setlocale(LC_ALL, "russian");

	printf("\n ������� ������ ������� N*N: ");
	scanf("%d", &N);

	printf("\n ��������������� ����?");
	printf("\n �� - 1 ");
	printf("\n ��� - 2\n\n");
	
	c = _getch();
	if(c == 49)
		naprav = 1;

	M1 = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		M1[i] = (int*)malloc(N * sizeof(int));
	}

	nodes.resize(N);

	srand(time(NULL));
	int ch = 0;
	for (int i = 0; i < N; i++) // ��������� ������� M1 (���������� �����������������)
	{
		M1[i][i] = 0;

		for (int j = i + 1; j < N; j++)
		{

			ch = rand() % 10;
			if (ch < 7)
				M1[i][j] = ch;
			else
				M1[i][j] = 0;

			M1[j][i] = M1[i][j];


		}
	}

	M2 = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		M2[i] = (int*)malloc(N * sizeof(int));
	}

	for (int i = 0; i < N; i++) // ��������� ������� M2 (���������� ��������������� ����)
	{
		M2[i][i] = 0;

		for (int j = 0; j < N; j++)
		{

			ch = rand() % 15;
			if (ch < 12)
			{
				if (ch > 9)
					ch = ch - 6;

				M2[i][j] = ch;
				M2[j][i] = 0;

			}

			else
			{
				M2[i][j] = 0;
			}

		}
	}

	if(naprav == 1)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				M1[i][j] = M2[i][j];

	
}



void bellman_ford() //�������� ��������-�����
{
	int i, j;

	ofstream fout;

	fout.open("../../bellman_ford.txt", ios::app);

	if (!fout.is_open())
	{
		cout << "\n ������ �������� �����";
		_Exit(EXIT_SUCCESS);
	}

	for (i = 0; i < N; i++) 
		nodes[i] = inf;

	vector<int> parent(N, -1);

	nodes[st] = 0;

	
	for (i = 0; i < N - 1; i++)
	{ 
		bool change = false; 

		for (j = 0; j < e; j++) // v -> u, w - ���
			if (nodes[edge[j].v] + edge[j].w < nodes[edge[j].u])
			{
				nodes[edge[j].u] = nodes[edge[j].v] + edge[j].w;
				parent[edge[j].u] = edge[j].v; 
				change = true;
			}
		
		if (!change)  // ���� �������� �� ���� ���������, ���������� �� ������������
			break;

	}

	

	for (i = 0; i < N; i++) 
	{
		if (nodes[i] == inf)
		{
			cout << endl << " " << st + 1 << " -> " << i + 1 << " = " << "���� ����������� ";
			fout << endl << " " << st + 1 << " -> " << i + 1 << " = " << "���� ����������� ";
		}
		else 
		{
			cout << endl << " " << st + 1 << " -> " << i + 1 << " = " << nodes[i];
			fout << endl << " " << st + 1 << " -> " << i + 1 << " = " << nodes[i];
			
	// �������������� ����
			if (nodes[i] < 10)
			{
				cout << " ";
				fout << " ";
			}
			vector<int> path; // ������ ��� �������������� ����
			for (int cur = i; cur != -1; cur = parent[cur])
				path.push_back(cur);
			reverse(path.begin(), path.end());
			
			cout << "  (";
			fout << "  (";
			for (size_t i = 0; i < path.size(); ++i)
				if ((i + 1) != path.size())
				{
					cout << path[i] + 1 << " -> ";
					fout << path[i] + 1 << " -> ";
				}
				else
				{
					cout << path[i] + 1;
					fout << path[i] + 1;
				}
			cout << ")";
			fout << ")";

		}

	}

	fout.close();
}


