#include <stdio.h>

#define M 20

int Hash(char symbol)
{
	return (int)symbol;
}


int main()
{
	char str[M];
	gets(str);
	int a=0;
	for (int i = 0; i < M; i++)
	{
		a = a + Hash(str[i]);
	}
	printf("\n %d", a);
	return 0;
}
