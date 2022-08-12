#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct Que
{
	int* data;
	int size;
	int count;
}Que;

void push(Que*);
int pop(Que*);
int size(Que*);
int empty(Que*);
int front(Que*);
int back(Que*);



int main()
{
	Que Que;
	Que.data = (int*)malloc(sizeof(int)*10000);
	Que.size = 0;
	Que.count = 0;
	int N;
	int input[100];
	scanf("%d", &N);
	if (N < 1 || N>10000)
		exit(0);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", input);
		if (strcmp(input, "push") == 0)
			push(&Que);
		if (strcmp(input, "pop") == 0)
			printf("%d\n",pop(&Que));
		if (strcmp(input, "size") == 0)
			printf("%d\n", size(&Que));
		if (strcmp(input, "empty") == 0)
			printf("%d\n", empty(&Que));
		if (strcmp(input, "front") == 0)
			printf("%d\n", front(&Que));
		if (strcmp(input, "back") == 0)
			printf("%d\n", back(&Que));;

	}

}

void push(Que* Q)
{
	int data;
	scanf("%d", &data);
	Q->data[Q->size++] = data;
}

int pop(Que* Q)
{
	if (empty(Q) == 1)
	{
		return -1;
	}
	return Q->data[Q->count++];
}

int size(Que* Q)
{
	return Q->size - Q->count;
}

int empty(Que* Q)
{
	if (Q->size - Q->count == 0)
		return 1;
	else
		return 0;
}

int front(Que* Q)
{
	if (empty(Q) == 1)
		return -1;
	else
		return Q->data[Q->count];

}

int back(Que* Q)
{
	if (empty(Q) == 1)
	{
		return -1;
	}
	else
		return Q->data[Q->size-1];
}