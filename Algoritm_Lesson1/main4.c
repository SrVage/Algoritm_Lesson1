// Krampit Maksim, lesson 1, task6

#include <stdio.h>


int main(int argc, const char* argv[])
{
	long a;
	printf("Vvedite vozrast: ");
	scanf("%i",&a);
	printf("%i", a);
	switch (a)
	{
	case 1: printf(" god"); break;
	case 2:
	case 3:
	case 4:
		printf(" goda"); break;
	default: printf(" let"); break;
	}
	return 0;
}