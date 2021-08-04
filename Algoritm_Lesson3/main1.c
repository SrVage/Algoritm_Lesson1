// Krampit Maksim, lesson 3, task1 && task2

#include <stdio.h>
#include <stdbool.h>
#include "main1.h"
// Определяем максимальный размер массива
#define MaxN 100
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
// Распечатываем массив
void print(int N, int* a)
{
	int i;
	for (i = 0; i < N; i++)
		printf("%6i", a[i]);
	printf("\n");
}
int main(int argc, char* argv[]) {
	int a[MaxN]; // создаём массив максимального размера
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
	puts("Array before sort");
	print(N, a);
	//DefaultSortingWithCheck(N, a);
	//EvenOddSorting(N, a);
	//CompSorting(N, a);
	ShakerSorting(N, a);
	printf("     ");
	puts("Array after sort");
	print(N, a);
	return 0;
}

void EvenOddSorting(int N, int  a[100])
{
	int oper = 0;
	for (int i = 0; i < N; i++)
	{
		int isChanged = 0;
		if (i % 2 == 0)
		{
			for (int j = 0; j < N - 1; j = j + 2)
			{
				oper++;
				if (a[j] > a[j + 1])
				{
					swap(&a[j], &a[j + 1]);
					isChanged = isChanged + 1;
				}
			}
		}
		else
		{
			for (int j = 1; j < N - 1; j = j + 2)
			{
				oper++;
				if (a[j] > a[j + 1])
				{
					swap(&a[j], &a[j + 1]);
					isChanged = isChanged + 1;
				}
			}
		}
		printf("Array after %i iteration", i + 1);
		print(N, a);
		if (isChanged == 0&& i%2==1)	break;
	}
		printf("Iteration %i", oper);
}

void DefaultSortingWithCheck(int N, int  a[100])
{
	int oper = 0;
	for (int i = 0; i < N; i++)
	{
		int isChanged = 0;
		for (int j = 0; j < N - 1; j++)
		{
			oper++;
			if (a[j] > a[j + 1])
			{
				
				swap(&a[j], &a[j + 1]);
				isChanged = isChanged + 1; //проверяем, былили перестановки за обход массива
			}
		}
		printf("Array after %i iteration", i + 1);
		print(N, a);
		if (isChanged == 0)	break; //если перестановок не было - прерываем цикл
	}
	printf("Iteration %i", oper);
}int GetGamp(int gap){	gap = (gap * 10) / 13;	if (gap < 1) gap = 1;	return gap;}void CompSorting(int N, int a[100]){	int oper = 0;	int gap = N;	int isChanged = 1;	int j = 0;	while (gap != 1 || isChanged > 0)	{		gap = GetGamp(gap);		isChanged = 0;		for (int i = 0; i < N - gap; i++)		{			oper++;			if (a[i] > a[i + gap])			{				swap(&a[i], &a[i + gap]);				isChanged = isChanged + 1;			}		}		j++;		printf("Array after %i iteration", j + 1);
		print(N, a);	}	printf("Iteration %i", oper);}void ShakerSorting(int N, int a[100]) //task 2{	int oper = 0;
	for (int i = 0; i < N; i++)
	{
		int isChanged = 0;
		for (int j = i; j < N - 1-i; j++)
		{
			oper++;
			if (a[j] > a[j + 1])
			{

				swap(&a[j], &a[j + 1]);
				isChanged = isChanged + 1; //проверяем, былили перестановки за обход массива
			}
		}
		for (int j = N-2-i; j > i; j--)
		{
			oper++;
			if (a[j] > a[j + 1])
			{

				swap(&a[j], &a[j + 1]);
				isChanged = isChanged + 1; //проверяем, былили перестановки за обход массива
			}
		}
		printf("Array after %i iteration", i + 1);
		print(N, a);
		if (isChanged == 0)	break; //если перестановок не было - прерываем цикл
	}
	printf("Iteration %i", oper);}