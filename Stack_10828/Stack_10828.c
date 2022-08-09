#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct
{
	int* data;
	int size;
}Stack;

void push(Stack*, int);
void pop(Stack*);
void size(Stack*);
void empty(Stack*);
void top(Stack*);

int main()
{
	int N;
	int i;
	scanf("%d", &N);
	Stack stack;
	stack.size = 0;
	stack.data = calloc(100, sizeof(int));
	for (i = 0; i < N; i++)
	{
		char input[50];
		int num;
		scanf("%s", input);
		if (strcmp(input, "push") == 0)		//push�� �Է����� ���
		{
			scanf("%d", &num);
			push(&stack, num);
		}
		else if (strcmp(input, "pop") == 0)		//pop�� �Է����� ���
		{
			pop(&stack);
		}
		else if (strcmp(input, "size") == 0)		//size�� �Է����� ���
		{
			size(&stack);
		}
		else if (strcmp(input, "empty") == 0)		//empty�� �Է����� ���
		{
			empty(&stack);
		}
		else if (strcmp(input, "top") == 0)		//top�� �Է����� ���
		{
			top(&stack);
		}
	}

}

void push(Stack* st,int n)
{
	st->data[st->size++] = n;
}

void pop(Stack* st)
{
	if (st->size == 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", st->data[--st->size]);
	}
}

void size(Stack* st)
{
	printf("%d\n", st->size);
}

void empty(Stack* st)
{
	if (st->size == 0)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
}

void top(Stack* st)
{
	if (st->size == 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", st->data[st->size-1]);
	}
}