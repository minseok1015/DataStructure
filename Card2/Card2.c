#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct que
{
	int* data;
	int size;
	int point;
}que;

void start_card(que*, int);
int reculsive(que*);

int main()
{
	int N;
	scanf("%d",&N);
	if (N < 1 || N>500000) exit(0);
	que que;
	que.data = (int*)malloc(sizeof(int)*5000000);
	que.size = 0;
	que.point = 0;
	start_card(&que, N);
	printf("%d", reculsive(&que));
}

void start_card(que* q, int n)
{
	for (int i = 1; i <= n; i++)
	{
		q->data[q->size++] = i;
	}
}

int reculsive(que* q)
{
	while (q->size-1 > q->point)
	{
		q->point++;
		q->data[q->size++] = q->data[q->point++];
	}
	return q->data[q->size-1];
}