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



#define INFTY INT_MAX
int** M1, **M2;
int N;
void generation();
void bellman_ford();

using namespace std;
vector <int> nodes; // ������ ����������
int st = 0; // ��������� �������


#define inf 2000000000
using namespace std;
struct Edges {
	int u, v, w;
};

const int Emax = 1000;
int i, j, n, e, start;

Edges edge[Emax]; // ����� ����



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

input:
	cout << "\n �������� ������ ����� �����";
	cout << "\n 1 - �������";
	cout << "\n 2 - ��������� �� ����� input.txt";
	cout << "\n 3 - ��������� ���������";
input2:
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

	else if (c == 50) // ���������� �� �����
	{
		ifstream fin;
		fin.open("../../input.txt");

		if (!fin.is_open()) 
		{
			cout << "\n\n ������ �������� �����";
			cout << "\n ��������� ������������� ����� input.txt";
			cout << "\n ��� ���������� ������ ��������� ���� ������ ���� �������� � ����� ����:";
			cout << "\n ������ ������ - ���-�� ������";
			cout << "\n ������� �� ������ - ������� ���������";

			cout << "\n\n ������ ����������:";
			cout << "\n 3 ";
			cout << "\n 0 8 0 ";
			cout << "\n 3 0 0 ";
			cout << "\n 4 0 0\n ";


			fout.close();

			fout.open("../../input.txt");
			fout.close();

			goto input;

		}
		
		cout << "\n\n ���� ������";

		
		
		fin >> N; // ����� �����
		
		cout << "\n\n ���������� ������ > " << N << endl; 
		nodes.resize(N);
		M1 = (int**)malloc(N * sizeof(int*));
		for (int i = 0; i < N; i++)
		{
			M1[i] = (int*)malloc(N * sizeof(int));
		}

		//������� ������� �� �����
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				fin >> M1[i][j];

		fin.close();
		
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
		cout << "\n";
	}
		
	else if (c == 51)
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

	else
		goto input2;
	

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
				if(M1[i][j] < 0)
					cout << '\b';

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

	
	for (int i = N - 1; i > 0; i--) 
	{ // �������� ������
		free(M1[i]);
		
	}
	free(M1);
	
	
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
	int ch2 = 0;
	for (int i = 0; i < N; i++) // ��������� ������� M1 (���������� �����������������)
	{
		M1[i][i] = 0;

		for (int j = i + 1; j < N; j++)
		{

			ch = rand() % 10;
			ch2 = rand() % 100;
			if (ch < 7)
			{
				if (ch2 < 1)
					ch = -ch;

				M1[i][j] = ch;

			}
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
			ch2 = rand() % 100;
			if (ch < 12)
			{
				if (ch > 9)
					ch = ch - 6;

				if (ch2 < 1)
					ch = -ch;

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

	for (int i = N - 1; i > 0; i--)
	{ // �������� ������
		free(M2[i]);
	}
	free(M2);

	
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
	
	int x;
	
	for (i = 0; i < N - 1 ; i++)
	{ 
		
				
		bool change = false; 

		for (j = 0; j < e; j++) // v -> u, w - ���
			if (nodes[edge[j].v] + edge[j].w < nodes[edge[j].u])
			{
				
				
				nodes[edge[j].u] = max(-inf, nodes[edge[j].v] + edge[j].w); // ������ �� ������������
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


			if (nodes[i] >= 0 && nodes[i] < 10)
			{
				cout << " ";
				fout << " ";
			}
	
			vector<int> path; // ������ ��� �������������� ����
			
			for (int cur = i; cur != -1; cur = parent[cur])
			{
				
				
				for (int i2 = 0; i2 < path.size(); i2++)
					if (cur == path[i2] && path.size() > 1) // ���� ����� ������ �������� �������� � ��� ����������
					{									   // ������� - ������������� ����
						path.push_back(cur);
						cout << " (������������� ����)";
						fout << " (������������� ����)";
						goto negative;
					}
				

				path.push_back(cur);

			}
			
		negative:
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


