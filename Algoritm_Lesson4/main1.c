// Krampit Maksim, lesson 4, task1

#include <stdio.h>
#define N 4
#define M 4
#define MaxK 100
void Print2(int n, int m, int a[N][M])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
}
int main(int argc, char* argv[])
{
	int a[N][M];
	int K;
	FILE* in;
	in = fopen("d:\\temp\\data.txt", "r");
	fscanf(in, "%i", &K);
	int i;
	int j;
	for (i = 0; i < K; i++)
	{
		for (j = 0; j < K; j++)
		{
			fscanf(in, "%i", &a[i][j]);
		}
	}
	fclose(in);
	int A[N][M];
	i, j;
	for (j = 0; j < M; j++)
	{
		if (a[0][j] == 1)
			A[0][j] = 1; // Первая строка заполнена единицами
		else
			A[0][j] = 0;
	}
		
	for (i = 1; i < N; i++)
	{
		if (a[i][0] == 1)
			A[i][0] = 1;
		else
			A[i][0] = 0;
		for (j = 1; j < M; j++)
		{
			if (a[i][j] == 1)
				A[i][j] = A[i][j - 1] + A[i - 1][j];
			else
				A[i][j] = 0;
		}
			
	}
	Print2(N, M, A);
	return 0;
}
