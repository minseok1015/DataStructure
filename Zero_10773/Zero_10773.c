#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
	int* data;
	int size;
}Stack;;

void push(Stack* s,int);
void pop(Stack* s);
int sum(Stack* s);

int main()
{
	Stack stack;
	stack.size = 0;
	stack.data = (int*)malloc(sizeof(int) * 100000);
	int K,N;
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &N);
		if (N < 0 || N>1000000)
		{
			exit(0);
		}
		else if (N == 0)
			pop(&stack);
		else
			push(&stack, N);
	}
	printf("%d", sum(&stack));
}

void push(Stack* s,int data)
{
	s->data[s->size++] = data;
}

void pop(Stack* s)
{
	s->data[--s->size] = NULL;
}

int sum(Stack* s)
{
	int num = 0;
	for (int i = 0; i < s->size; i++)
	{
		num += s->data[i];
	}
	return num;
}