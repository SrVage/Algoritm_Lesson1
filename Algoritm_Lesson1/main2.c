// Krampit Maksim, lesson 1, task2

#include <stdio.h>

double Max(double a, double b, double c, double d)
{
	double max1, max2;
	if (a > b) max1 = a;
	else max1 = b;
	if (c > d) max2 = c;
	else max2 = d;
	if (max1 > max2) return max1;
	else return max2;
}

int main(int argc, const char* argv[])
{
	double a, b, c, d;
	printf("Please, input 4 number");

	scanf("%lf", &a);
	scanf("%lf", & b);
	scanf("%lf", &c);
	scanf("%lf", &d);
	printf("%lf", Max(a, b, c, d));
	return 0;
}