// Krampit Maksim, lesson 2, task1
#include "stdio.h"

int ToBinary(int a)
{
	if (a > 0)
	{
	 printf("%i", a%2, ToBinary(a / 2));
	}
}

int main(int argc, const char* argv[])
{
	int number;
	scanf("%i", &number);
	ToBinary(number);
}