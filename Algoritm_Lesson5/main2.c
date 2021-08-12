// Krampit Maksim, lesson 2, task1
#include "stdio.h"
#include <malloc.h>
#define T char
#define M 10
// Опишем структуру узла списка
struct TNode
{
	T value;
	struct TNode* next;
};
typedef struct TNode Node;
struct Stack
{
	Node* head;
	int size;
	int maxSize;
};
struct Stack Stack;

void push(T value)
{
	if (Stack.size >= Stack.maxSize) {
		printf("Error stack size");
		return;
	}
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = Stack.head;
	Stack.head = tmp;
	Stack.size++;
}

T show()
{
	if (Stack.size == 0)
	{
		printf("Stack is empty");
		return;
	}
	T value;
	value = Stack.head->value;
	return value;
}
T pop() {
	if (Stack.size == 0)
	{
		printf("Stack is empty");
		return;
	}
	// Временный указатель
	Node* next = NULL;
	// Значение "наверху" списка
	T value;
	value = Stack.head->value;
	next = Stack.head;
	Stack.head = Stack.head->next;
	// Запись, на которую указывала голова удаляем, освобождая память
	free(next);
	// Возвращаем значение, которое было в голове
	Stack.size--;
	return value;
}
void PrintStack()
{
	Node* current = Stack.head;
	while (current != NULL)
	{
		printf("%c", current->value);
		current = current->next;
	}
}

int main(int argc, const char* argv[])
{
	char mas[M];
	Stack.maxSize = 100;
	Stack.head = NULL;
	gets(mas);
	puts(mas);
	for (int i = 0; i < M; i++)
	{
		//printf("Head = %c ", show());
		//printf("Element = %c ", mas[i]);
		if (mas[i] == NULL) break;
		if (mas[i] == '(' || mas[i] == '{' || mas[i] == '[')
		{
			push(mas[i]);
		}
		else if (mas[i] == ')' && show() == '(')
		{
			pop();
		}
		else if (mas[i] == '}' && show() == '{')
		{
			pop();
		}
		else if (mas[i] == ']' && show() == '[')
		{
			pop;
		}
		else
		{
			printf("Mistake");
			return;
		}
	}
	//PrintStack();
	if (Stack.size == 0)
	{
		printf("All right");
	}
	else 
	{
		printf("Mistake");
	}
}