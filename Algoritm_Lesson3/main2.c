// Krampit Maksim, lesson 3, task3

#include <stdio.h>
#include <stdbool.h>
#include "main2.h"
// ќпредел€ем максимальный размер массива
#define MaxN 100
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
// –аспечатываем массив
void print(int N, int* a)
{
	int i;
	for (i = 0; i < N; i++)
		printf("%6i", a[i]);
	printf("\n");
}
int main(int argc, char* argv[]) {
	int a[MaxN]; // создаЄм массив максимального размера
	int N;
	FILE* in;
	in = fopen("d:\\temp\\data.txt", "r");
	fscanf(in, "%i", &N);
	int i;
	for (i = 0; i < N; i++)
	{
		fscanf(in, "%i", &a[i]);
	}
	fclose(in);
	DefaultSortingWithCheck(N, a);
	printf("Input found number");
	int value;
	scanf("%i", &value);
	puts("Array after sort");
	print(N, a);
	int find = BinaryFind(N, a, value);
	if (find == -1) printf("Not found");
	else printf("Found index is %i", find);
	return 0;
}


void DefaultSortingWithCheck(int N, int  a[100])
{
	for (int i = 0; i < N; i++)
	{
		int isChanged = 0;
		for (int j = 0; j < N - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				
				swap(&a[j], &a[j + 1]);
				isChanged = isChanged + 1; //провер€ем, былили перестановки за обход массива
			}
		}
		if (isChanged == 0)	break; //если перестановок не было - прерываем цикл
	}
}

int BinaryFind(int N, int  a[100], int value)
{
	int min = 0;
	int max = N - 1;
	int mid = min + (max - min) / 2;
	while (min <= max && a[mid] != value)
	{
		if (value < a[mid])
			max = mid - 1;
		else
			min = mid + 1;
		mid = min + (max - min) / 2;
	}
	if (a[mid] == value) return mid+1;
	else return -1;
}