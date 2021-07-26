// Krampit Maksim, lesson 1, task1

#include <stdio.h>

double indexOfMass(double h, double w)
{
	return (w / (h * h));
}

int main(int argc, const char* argv[])
{
	double height;
	double weight;
	printf("Please, input your weight in killogramms: ");
	scanf("%lf", &weight);
	printf("Please, input your height in meters: ");
	scanf("%lf", &height);
	printf("Index of mass: %lf", indexOfMass(height, weight));
	printf("\n");
	if (indexOfMass(height, weight) < 20)
		printf("Your weight is small");
	else if (indexOfMass(height, weight) > 25)
		printf("You've big weight");
	else printf("You've a normal weight");
	return 0;
}