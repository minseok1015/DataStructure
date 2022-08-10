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
int pop(Stack*);
int size(Stack*);
int empty(Stack*);
int top(Stack*);

int main()
{
	int N;
	int i;
	scanf("%d", &N);
	if (N < 0 || N>10000)
	{
		printf("error\n");
		exit(0);
	}
	Stack stack;
	stack.size = 0;
	stack.data = calloc(100, sizeof(int));
	for (i = 0; i < N; i++)
	{
		char input[50];
		int num;
		scanf("%s", input);
		if (strcmp(input, "push") == 0)		//push를 입력했을 경우
		{
			scanf("%d", &num);
			if (num < 0 || num>100000)
			{
				printf("error\n");
				exit(0);
			}
			push(&stack, num);
		}
		else if (strcmp(input, "pop") == 0)		//pop를 입력했을 경우
		{
			printf("%d\n",pop(&stack));
		}
		else if (strcmp(input, "size") == 0)		//size를 입력했을 경우
		{
			printf("%d\n",size(&stack));
		}
		else if (strcmp(input, "empty") == 0)		//empty를 입력했을 경우
		{
			printf("%d\n",empty(&stack));
		}
		else if (strcmp(input, "top") == 0)		//top을 입력했을 경우
		{
			printf("%d\n",top(&stack));
		}
	}

}

void push(Stack* st,int n)
{
	st->data[st->size++] = n;
}

int pop(Stack* st)
{
	if (st->size == 0)
	{
		return -1;
	}
	else
	{
		return st->data[--st->size];
	}
}

int size(Stack* st)
{
	return st->size;
}

int empty(Stack* st)
{
	if (st->size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int top(Stack* st)
{
	if (st->size == 0)
	{
		return -1;
	}
	else
	{
		return st->data[st->size-1];
	}
}