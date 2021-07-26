// Krampit Maksim, lesson 1, task3

#include <stdio.h>


int main(int argc, const char* argv[])
{
	double a, b, temp;
	printf("Please, input 2 number");
	scanf("%lf", &a);
	scanf("%lf", &b);
	//first
	//temp = a;
	//a = b;
	//b = temp;
	//second
	//a = a + b;
	//b = a - b;
	//a = a - b;
	//third
	//a = a ^ b;
	//b = b ^ a;
	//a = a ^ b;
	//fourth
	a = a * b;
	b = a / b;
	a = a / b;
	printf("%lf", a);
	printf("\n");
	printf("%lf", b);
	return 0;
}