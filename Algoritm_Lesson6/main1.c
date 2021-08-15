#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
} Node;

// –аспечатка двоичного дерева в виде скобочной записи
void printTree(Node* root)
{
	if (root)
	{
		printf("%d", root->data);
		if (root->left || root->right)
		{
			printf("(");

			if (root->left)
				printTree(root->left);
			else
				printf("NULL");
			printf(",");

			if (root->right)
				printTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
}

// —оздание нового узла
Node* getTreeNode(int value, Node* parent)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

// ¬ставка узла
void insert(Node** head, int value) {
	Node* tmp = NULL;
	if (*head == NULL)
	{
		*head = getTreeNode(value, NULL);
		return;
	}

	tmp = *head;
	while (tmp)
	{
		if (value > tmp->data)
		{
			if (tmp->right)
			{
				tmp = tmp->right;
				continue;
			}
			else
			{
				tmp->right = getTreeNode(value, tmp);
				return;
			}
		}
		else if (value < tmp->data)
		{
			if (tmp->left)
			{
				tmp = tmp->left;
				continue;
			}
			else
			{
				tmp->left = getTreeNode(value, tmp);
				return;
			}
		}
		else
		{
			exit(2);                                // дерево построено неправильно
		}
	}
}

void preOrderTravers(Node* root)
{
	if (root)
	{
		printf("%d ", root->data);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}

void Symmetry(Node* node)
{
	if (node)
	{
		Symmetry(node->left);
		printf("%d ", node->data);
		Symmetry(node->right);
	}
}

void Inverse(Node* node)
{
	if (node)
	{
		Inverse(node->left);
		Inverse(node->right);
		printf("%d ", node->data);
	}
}

void Find(int* number, Node* node)
{
	if (node)
	{
		if (node->data == number)
			printf("%d Find", node->data);
		else
		{
			if (node->data <= number)
				Find(number, node->right);
			else Find(number, node->left);
		}
	}
	else
		printf("Not find");
}

void FindNumber(Node* node)
{
	printf("\nInput find number");
	int a;
	scanf("%d", &a);
	Find(a, node);
}


int main()
{
	Node* Tree = NULL;
	FILE* file = fopen("E://data.txt", "r");

	if (file == NULL)
	{
		puts("Can't open file!");
		getch();
	}
	int count;
	fscanf(file, "%d", &count);          // —читываем количество записей
	int i;
	for (i = 0; i < count; i++)
	{
		int value;
		fscanf(file, "%d", &value);
		insert(&Tree, value);
	}
	fclose(file);
	printTree(Tree);
	printf("\nPress 1 to PreOrder Travers");
	printf("\nPress 2 to Symetry Travers");
	printf("\nPress 3 to Inverse Travers");
	printf("\nPress 4 to Find");
	switch (getch())
	{
	case '1': printf("\nPreOrderTravers:");
		preOrderTravers(Tree); break;
	case '2': printf("\nSymmetry:");
		Symmetry(Tree); break;
	case '3': printf("\nInverse:");
		Inverse(Tree); break;
	case '4': FindNumber(Tree); break;
	default:
		break;
	}
	getch();
	return 0;
}
