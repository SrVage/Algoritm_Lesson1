// Krampit Maksim, lesson 7, task1-2
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

const char* filename = "E:\graph.txt";

#define MAX_N  5
int G[MAX_N][MAX_N], visited[MAX_N], n;


int loadGraph()
{
	FILE* file = NULL;
	fopen_s(&file, filename, "r");
	if (file == NULL)
	{
		puts("Can't open file");
		exit(1);
	}
	int data = 0;
	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_N; j++)
		{
			if (fscanf_s(file, "%d", &data) == 0)
			{
				puts("Can't read matrix data");
				exit(3);
			}
			G[i][j] = data;
		}
	fclose(file);
}

void printMatrix()
{
	printf("%4d\n", MAX_N);
	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j < MAX_N; j++)
		{
			printf_s("%4d", G[i][j]);
		}
		printf_s("\n");
	}
}

void Deep(int i)
{
	int j;
	printf("\n%d", i);
	visited[i] = 1;

	for (j = 0; j < MAX_N; j++)
		if (!visited[j] && G[i][j] == 1)
			Deep(j);
}

int main()
{
	loadGraph();
	printMatrix();
	Deep(3);
	return 0;
}