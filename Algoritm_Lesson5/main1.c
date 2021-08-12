// Krampit Maksim, lesson 2, task1
#include "stdio.h"
#include <malloc.h>
#define T int
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
		printf("%i", current->value);
		current = current->next;
	}
}

void ToBinary(int a)
{
	while (a > 0)
	{
		push(a % 2);
		a = a / 2;
	}
	PrintStack();
}

int main(int argc, const char* argv[])
{
	int number;
	Stack.maxSize = 100;
	Stack.head = NULL;
	scanf("%i", &number);
	ToBinary(number);
	
}