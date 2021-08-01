// Krampit Maksim, lesson 2, task2
#include "stdio.h"

int NumberInDegree(int number, int degree)
{
	if (degree > 0)
	{
		return number * NumberInDegree(number, degree - 1);
	}
	else {
		return 1;
	}
}

int main(int argc, const char* argv[])
{
	int number;
	int answer = 1;
	int degree;
	scanf("%i", &number);
	scanf("%i", &degree);
	//for (int i = 0; i < degree; i++)
	//	{
	//		answer = answer * number;
	//	}
	//printf("%i", answer);
	if (degree%2==0)
		printf("%i", NumberInDegree(NumberInDegree(number, degree/2),2));
	else
	printf("%i", NumberInDegree(number, degree));
}