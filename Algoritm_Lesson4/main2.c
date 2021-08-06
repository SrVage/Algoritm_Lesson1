// Krampit Maksim, lesson 4, task2

#include <stdio.h>
#include <math.h>
#define N 8
#define M 8

// Доска для ферзей.
// 0 - клетка пустая
// число - номер ферзя

int board[N][M];
int moves[8][2] = { {1,2}, {1, -2}, {-1,2}, {-1,-2}, {2,1}, {2,-1}, {-2,1}, {-2,-1} };
int SearchSolution(int n, int row, int col);
int CheckBoard(int row, int col);
int CheckHorse(int x, int y);
void Print(int n, int m, int a[N][M]);
void Zero(int n, int m, int a[N][M]);

int main()
{
	Zero(N, M, board);
	SearchSolution(1, 4, 0);
	printf("\n\n");
	Print(N, M, board);

	getch();
	return 0;
}

int SearchSolution(int n, int row, int col)
{
	// Если проверка доски возвращает 0, то эта расстановка не подходит
	int r, c;
	if (CheckBoard(row, col) == 0)
	{
		return 0;
	}
	if (n == M*N+1)
	{
		return 1;
	}
	for (int k = 0; k < 8; k++)
	{
		r = row + moves[k][0];
		c = col + moves[k][1];
		if ((r >= N || r < 0) || (c >= M || c < 0)) continue;
			if (board[r][c] == 0)
			{
				// Расширяем test_solution
				board[r][c] = n;
				//Print(N, M, board);
				//printf("\n\n");
				// Рекурсивно проверяем, ведет ли это к решению.
				if (SearchSolution((n + 1), r, c)) return 1;
				// Если мы дошли до этой строки, данное частичное решение
				// не приводит к полному.
				board[r][c] = 0;
			}
	}
	return 0;
}

// Проверка всей доски
int CheckBoard(int row, int col)
{
	if (CheckHorse(row, col) == 0)
	{
		return 0;
	}
	return 1;
}

// Проверка определённого ферзя
int CheckHorse(int x, int y)
{
	int i, j;
	for (int k = 0; k < 8; k++)
	{
		if (board[x + moves[k][0]][y + moves[k][1]] == 0 && ((x + moves[k][0] < N) || (x + moves[k][0] > 0)) && ((y + moves[k][1] < M) || (y + moves[k][1] > 0)))
			return 1;
	}
	return 0;
}

// Выводим доску на экран
void Print(int n, int m, int a[N][M])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
		printf("\n");
	}
}

// Очищаем доску
void Zero(int n, int m, int a[N][M])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			a[i][j] = 0;
		}
	}
}