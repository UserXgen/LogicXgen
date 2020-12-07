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
void zad1_2(int st);
void zad1_3(int st);
void zad1_4(int st);
void zad1_5(int st);
void zad1_nevzv();

#define INFTY INT_MAX
int** M1, ** M2, *nodes, *ex, *dom, *kon;
int N;


using namespace std;
queue <int> Q;
int st = 0;


void main(int argc, char* argv[])
{

	int naprav = 0, ves = 0;

	setlocale(LC_CTYPE, "rus");
	/*
	if (argc == 1)
	{
	printf("\n ������� ��������� Lab7.exe <��������������> <���>\n\n");
	printf(" ���������:\n");
	printf(" dir - ��������������� ����\n");
	printf(" weight - ���������� ����\n");

	_Exit(EXIT_SUCCESS);
	}
	*/
	ves = 1;
	naprav = 0;
	int inc = 0;
	for (int i = 0; i < argc; ++i)
	{
		if (strcmp(argv[i], "dir") == 0) // dir dis
			naprav = 1;

		if (strcmp(argv[i], "weight") == 0) // weigh unweigh
			ves = 1;
	}

	if (ves == 1)
		zad1();
	else
		zad1_nevzv();

	if (naprav == 1)
	{
		zad1_3(st); // ��������������� ����
		zad1_5(st);
	}
	else
	{
		zad1_2(st); // ����������������� ����
		zad1_4(st);
	}


	std::cout << '\n';


	_getch();

}

void zad1()
{

	setlocale(LC_ALL, "russian");

	printf("\n ������� ������ ������� N*N: ");
	scanf("%d", &N);

	M1 = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		M1[i] = (int*)malloc(N * sizeof(int));
	}

	nodes = (int*)malloc(N * sizeof(int));
	ex = (int*)malloc(N * sizeof(int));
	dom = (int*)malloc(N * sizeof(int));
	kon = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		ex[i] = -1;
		dom[i] = -1;
		kon[i] = -1;
	}

	srand(time(NULL));
	int ch = 0;
	for (int i = 0; i < N; i++) // ��������� ������� M1 (���������� �����������������)
	{
		M1[i][i] = 0;

		for (int j = i + 1; j < N; j++)
		{

			ch = rand() % 10;
			if (ch < 5)
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

			ch = rand() % 10;
			if (ch < 7)
			{
				M2[i][j] = ch;
				M2[j][i] = 0;

			}

			else
			{
				M2[i][j] = 0;
			}

		}
	}


}

void zad1_nevzv()
{
	setlocale(LC_ALL, "russian");

	printf("\n ������� ������ ������� N*N: ");
	scanf("%d", &N);

	M1 = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		M1[i] = (int*)malloc(N * sizeof(int));
	}

	M2 = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		M2[i] = (int*)malloc(N * sizeof(int));
	}

	nodes = (int*)malloc(N * sizeof(int));

	ex = (int*)malloc(N * sizeof(int));
	dom = (int*)malloc(N * sizeof(int));
	kon = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		ex[i] = -1;
		dom[i] = -1;
		kon[i] = -1;
	}


	srand(time(NULL));
	int ch = 0;
	for (int i = 0; i < N; i++) // ��������� ������� M1 (������������ �����������������)
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

	for (int i = 0; i < N; i++) // ��������� ������� M2 (������������ ���������������)
	{
		M2[i][i] = 0;

		for (int j = 0; j < N; j++)
		{

			ch = rand() % 10;
			if (ch < 7)
			{
				M2[i][j] = 1;
				M2[j][i] = 0;

			}

			else
			{
				M2[i][j] = 0;
			}


		}
	}

}


void zad1_2(int st)
{
	int r, i = 0;

	///// ����� ������� ���������
	printf("    ");
	for (int i = 0; i < N; i++)
		printf("[%d] ", i + 1);

	for (int i = 0; i < N; i++)
	{
		printf("\n[%d]", i + 1);

		for (int j = 0; j < N; j++)
		{
			if ((i + 1) < 10)
			{
				if (j < 10)
					printf("%3d ", M1[i][j]);
				else
					printf(" %3d ", M1[i][j]);

			}

			else if ((i + 1) < 100)
			{
				if (j == 0)
					printf(" %d", M1[i][j]);
				else if (j < 10)
					printf("   %d", M1[i][j]);
				else
					printf("    %d", M1[i][j]);

			}

		}

	}
	/////
	int sch2 = 0;
	printf("\n\n ����� ���������� �� ������ ������ � ������ ������� ��������� ������������������ ����� ��� ������ �� ������");
	for (int j = 0; j < N; j++)
	{
		sch2 = 0;
		printf("\n ");

		for (int i = 0; i < N; i++) // ������� ��� ������� ����� 10000
			nodes[i] = 10000;

		st = j;
		Q.push(st);
		int nach = st;

		nodes[st] = 0;

		while (!Q.empty())
		{
			st = Q.front();
			Q.pop();

			for (r = 0; r < N; r++)
				if ((M1[st][r] != 0) && (nodes[r] > nodes[st] + M1[st][r])) // ����� ���������� � ������� �� ��������
				{
					Q.push(r);
					nodes[r] = nodes[st] + M1[st][r];
				}
		}
		for (int i = 0; i < N; i++)
		{
			if (nodes[i] != 10000)
			{
				printf("%d ", nodes[i]);
				sch2++;
			}
			else
			{
				nodes[i] = 0;
				printf("0 ");
			}
			if (nodes[i] > ex[nach])
			{
				ex[nach] = nodes[i];
			}
		}
		if (sch2 == N)
			dom[j] = j;
		if (sch2 == 2)
			kon[j] = j;
	}

	/// ///

	int rad = 10000;
	int dia = 0;
	for (int i = 0; i < N; i++)
		if (ex[i] == 10000)
			ex[i] = 0;
	printf("\n���������������: \n");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", ex[i]);
		if (ex[i] > dia)
			dia = ex[i];
		if ((ex[i] < rad) && (ex[i] != 0))
			rad = ex[i];
	}
	if (rad == 10000)
		rad = 0;
	int sch1 = 0;
	printf("\n������ - %d, ������� - %d\n", rad, dia);
	printf("����������� �������: \n");
	for (int i = 0; i < N; i++)
	{
		if (ex[i] == rad)
		{
			printf("%d ", i + 1);
			sch1++;
		}
	}
	if (sch1 == 0)
		printf(" �����������");
	sch1 = 0;
	printf("\n������������ �������: \n");
	for (int i = 0; i < N; i++)
	{
		if (ex[i] == dia)
			printf("%d ", i + 1);
	}
	printf("\n������������� �������: \n");

	for (int i = 0; i < N; i++)
	{
		if (ex[i] == 0)
		{
			printf("%d ", i + 1);
			sch1++;
		}
	}
	if (sch1 == 0)
		printf("�����������");
	printf("\n������������ �������: \n");
	for (int i = 0; i < N; i++)
	{
		if (dom[i] != -1)
		{
			printf("%d ", i + 1);
		}
	}
	printf("\n�������� �������: \n");
	for (int i = 0; i < N; i++)
	{
		if (kon[i] != -1)
		{
			printf("%d ", i + 1);
		}
	}
}


void zad1_3(int st)
{
	int r, i = 0;

	///// ����� ������� ���������
	printf("    ");
	for (int i = 0; i < N; i++)
		printf("[%d] ", i + 1);

	for (int i = 0; i < N; i++)
	{
		printf("\n[%d]", i + 1);

		for (int j = 0; j < N; j++)
		{
			if ((i + 1) < 10)
			{
				if (j < 10)
					printf("%3d ", M2[i][j]);
				else
					printf(" %3d ", M2[i][j]);

			}

			else if ((i + 1) < 100)
			{
				if (j == 0)
					printf(" %d", M2[i][j]);
				else if (j < 10)
					printf("   %d", M2[i][j]);
				else
					printf("    %d", M2[i][j]);

			}

		}

	}
	/////
	int sch2 = 0;
	printf("\n\n ����� ���������� �� ������ ������ � ������ ������� ��������� ���������������� ����� ��� ������ �� ������");
	for (int j = 0; j < N; j++)
	{
		sch2 = 0;
		printf("\n ");

		for (int i = 0; i < N; i++) // ������� ��� ������� ����� 10000
			nodes[i] = 10000;

		st = j;
		Q.push(st);
		int nach = st;

		nodes[st] = 0;

		while (!Q.empty())
		{
			st = Q.front();
			Q.pop();

			for (r = 0; r < N; r++)
				if ((M2[st][r] != 0) && (nodes[r] > nodes[st] + M2[st][r])) // ����� ���������� � ������� �� ��������
				{
					Q.push(r);
					nodes[r] = nodes[st] + M2[st][r];
				}
		}
		for (int i = 0; i < N; i++)
		{
			if (nodes[i] != 10000)
			{
				printf("%d ", nodes[i]);
				sch2++;
			}
			else
			{
				nodes[i] = 0;
				printf("0 ");
			}
			if (nodes[i] > ex[nach])
			{
				ex[nach] = nodes[i];
			}
		}
		if (sch2 == N)
			dom[j] = j;
		if (sch2 == 2)
			kon[j] = j;
	}

	/// ///

	int rad = 10000;
	int dia = 0;
	for (int i = 0; i < N; i++)
		if (ex[i] == 10000)
			ex[i] = 0;
	printf("\n���������������: \n");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", ex[i]);
		if (ex[i] > dia)
			dia = ex[i];
		if ((ex[i] < rad) && (ex[i] != 0))
			rad = ex[i];
	}
	if (rad == 10000)
		rad = 0;
	int sch1 = 0;
	printf("\n������ - %d, ������� - %d\n", rad, dia);
	printf("����������� �������: \n");
	for (int i = 0; i < N; i++)
	{
		if (ex[i] == rad)
		{
			printf("%d ", i++);
			sch1++;
		}
	}
	if (sch1 == 0)
		printf(" �����������");
	sch1 = 0;
	printf("\n������������ �������: \n");
	for (int i = 0; i < N; i++)
	{
		if (ex[i] == dia)
			printf("%d ", i++);
	}
	printf("\n������������� �������: \n");

	for (int i = 0; i < N; i++)
	{
		if (ex[i] == 0)
		{
			printf("%d ", i++);
			sch1++;
		}
	}
	if (sch1 == 0)
		printf("�����������");
	printf("\n������������ �������: \n");
	for (int i = 0; i < N; i++)
	{
		if (dom[i] != -1)
		{
			printf("%d ", i++);
		}
	}
	printf("\n�������� �������: \n");
	for (int i = 0; i < N; i++)
	{
		if (kon[i] != -1)
		{
			printf("%d ", i++);
		}
	}
}
/// <summary>

/// </summary>


void zad1_4(int st)
{
	printf("������� �������������: \n");
	int r, i = 0;
	int j = 0;
	int reb = 0;
	int sch3 = 0;

	while (sch3 != N)
		for (int i = 0; i < N; i++)
		{
			for (int j = 0 + sch3; j < N; j++)
				if (M1[i][j] != 0)
					reb++;
			sch3++;
		}
	/////

	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			if (M1[i][j] != 0)
				M1[j][i] = 0;

	int** inc;

	inc = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		inc[i] = (int*)malloc(reb * sizeof(int));
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < reb; j++)
			inc[i][j] = 0;
	int	sch4 = reb;
	reb = 0;
	for (int i = 0; i < N; i++)				//�������� ������� �������������
	{
		for (int j = 0; j < N; j++)
			if (M1[i][j] != 0)
			{
				inc[i][reb] = 1;				//������
				inc[j][reb] = 1;				//�����
				reb++;
			}
	}


	printf("\n    ");
	for (int i = 0; i < sch4; i++)
		printf("[%d] ", i + 1);

	for (int i = 0; i < N; i++)
	{
		printf("\n[%d]", i + 1);

		for (int j = 0; j < reb; j++)
		{
			if ((i + 1) < 10)
			{
				if (j < 10)
					printf("%3d ", inc[i][j]);
				else
					printf(" %3d ", inc[i][j]);

			}

			else if ((i + 1) < 100)
			{
				if (j == 0)
					printf(" %d", inc[i][j]);
				else if (j < 10)
					printf("   %d", inc[i][j]);
				else
					printf("    %d", inc[i][j]);

			}

		}

	}

	int* ex1;
	ex1 = (int*)malloc(sch4 * sizeof(int));
	int* nodes1;
	nodes1 = (int*)malloc(sch4 * sizeof(int));
	for (int i = 0; i < sch4; i++)
	{
		nodes1[i] = -1;
		ex1[i] = -1;
	}




	int sch2 = 0;
	printf("\n\n ����� ���������� �� ������ ������ � ������ ������� ��������� ������������������ ����� ��� ������ �� ������");
	for (int j = 0; j < N; j++)
	{
		sch2 = 0;
		printf("\n ");

		for (int i = 0; i < sch4; i++) // ������� ��� ������� ����� 10000
			nodes1[i] = 10000;

		st = j;
		Q.push(st);
		int nach = st;

		nodes1[st] = 0;

		while (!Q.empty())
		{
			st = Q.front();
			Q.pop();

			for (r = 0; r < sch4; r++)
				if (st < N)
					if ((inc[st][r] != 0) && (nodes1[r] > nodes1[st] + inc[st][r])) // ����� ���������� � ������� �� ��������
					{
						Q.push(r);
						nodes1[r] = nodes1[st] + inc[st][r];
					}
		}
		for (int i = 0; i < sch4; i++)
		{
			if (nodes1[i] != 10000)
			{
				printf("%d ", nodes1[i]);
				sch2++;
			}
			else
			{
				nodes1[i] = 0;
				printf("0 ");
			}
			if (nodes1[i] > ex1[nach])
			{
				ex1[nach] = nodes1[i];
			}
		}
	}

	/// ///

	int rad = 10000;
	int dia = 0;
	for (int i = 0; i < sch4; i++)
		if (ex1[i] == 10000)
			ex1[i] = 0;
	printf("\n���������������: \n");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", ex1[i]);
		if (ex1[i] > dia)
			dia = ex1[i];
		if ((ex1[i] < rad) && (ex1[i] != 0))
			rad = ex1[i];
	}
	if (rad == 10000)
		rad = 0;
	int sch1 = 0;
	printf("\n������ - %d, ������� - %d\n", rad, dia);
	printf("����������� �������: \n");
	for (int i = 0; i < N; i++)
	{
		if (ex1[i] == rad)
		{
			printf("%d ", i++);
			sch1++;
		}
	}
	if (sch1 == 0)
		printf(" �����������");
	sch1 = 0;
	printf("\n������������ �������: \n");
	for (int i = 0; i < N; i++)
	{
		if (ex1[i] == dia)
			printf("%d ", i++);
	}
}

void zad1_5(int st)
{
	printf("������� �������������: \n");
	int r, i = 0;
	int j = 0;
	int reb = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)					//������� ���������� �����
			if (M2[i][j] != 0)
				reb++;
	}
	int** inc;

	inc = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		inc[i] = (int*)malloc(reb * sizeof(int));
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < reb; j++)
			inc[i][j] = 0;
	int	sch4 = reb;
	reb = 0;
	for (int i = 0; i < N; i++)				//�������� ������� �������������
	{
		for (int j = 0; j < N; j++)
			if (M2[i][j] != 0)
			{
				inc[i][reb] = 1;				//������
				inc[j][reb] = 2;				//�����
				reb++;
			}
	}

	int* ex1;
	ex1 = (int*)malloc(sch4 * sizeof(int));
	int* nodes1;
	nodes1 = (int*)malloc(sch4 * sizeof(int));
	for (int i = 0; i < sch4; i++)
	{
		nodes1[i] = -1;
		ex1[i] = -1;
	}


	printf("\n    ");
	for (int i = 0; i < sch4; i++)
		printf("[%d] ", i + 1);

	for (int i = 0; i < N; i++)
	{
		printf("\n[%d]", i + 1);

		for (int j = 0; j < sch4; j++)
		{
			if ((i + 1) < 10)
			{
				if (j < 10)
					printf("%3d ", inc[i][j]);
				else
					printf(" %3d ", inc[i][j]);

			}

			else if ((i + 1) < 100)
			{
				if (j == 0)
					printf(" %d", inc[i][j]);
				else if (j < 10)
					printf("   %d", inc[i][j]);
				else
					printf("    %d", inc[i][j]);
			}
		}
	}

	int sch2 = 0;
	printf("\n\n ����� ���������� �� ������ ������ � ������ ������� ��������� ���������������� ����� ��� ������ �� ������");
	for (int j = 0; j < N; j++)
	{
		sch2 = 0;
		printf("\n ");

		for (int i = 0; i < sch4; i++) // ������� ��� ������� ����� 10000
			nodes1[i] = 10000;

		st = j;
		Q.push(st);
		int nach = st;

		nodes1[st] = 0;

		while (!Q.empty())
		{
			st = Q.front();
			Q.pop();
			if (st < N)
				for (r = 0; r < sch4; r++)
					if ((inc[st][r] != 0) && (nodes1[r] > nodes1[st] + inc[st][r])) // ����� ���������� � ������� �� ��������
					{
						Q.push(r);
						nodes1[r] = nodes1[st] + inc[st][r];
					}
		}
		for (int i = 0; i < sch4; i++)
		{
			if (nodes1[i] != 10000)
			{
				printf("%d ", nodes1[i]);
				sch2++;
			}
			else
			{
				nodes1[i] = 0;
				printf("0 ");
			}
			if (nodes1[i] > ex1[nach])
			{
				ex1[nach] = nodes1[i];
			}
		}
	}

	/// ///

	int rad = 10000;
	int dia = 0;
	for (int i = 0; i < sch4; i++)
		if (ex1[i] == 10000)
			ex1[i] = 0;
	printf("\n���������������: \n");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", ex1[i]);
		if (ex1[i] > dia)
			dia = ex1[i];
		if ((ex1[i] < rad) && (ex1[i] != 0))
			rad = ex1[i];
	}
	if (rad == 10000)
		rad = 0;
	int sch1 = 0;
	printf("\n������ - %d, ������� - %d\n", rad, dia);
	printf("����������� �������: \n");
	for (int i = 0; i < N; i++)
	{
		if (ex1[i] == rad)
		{
			printf("%d ", i++);
			sch1++;
		}
	}
	if (sch1 == 0)
		printf(" �����������");
	sch1 = 0;
	printf("\n������������ �������: \n");
	for (int i = 0; i < N; i++)
	{
		if (ex1[i] == dia)
			printf("%d ", i++);
	}
}
