#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Quenode
{
	int data;
	struct Quenode* link;
}Quenode;

typedef struct Linked
{
	Quenode* front;
	Quenode* rear;
}Linked;


void make_que(Linked* q, int n);
int delete_que(Linked* q, int K);


int main()
{
	int N, K;
	scanf("%d", &N);
	scanf("%d", &K);
	if (K > N) exit(0);		// (1 ≤ K ≤ N ≤ 5,000) 조건을 위한 에러처리
	if (N > 5000|| N < 1) exit(0);
	Linked que;
	make_que(&que, N);
	
	printf("<");
	for (int i = 0; i < N; i++)
	{
		printf("%d", delete_que(&que, K));
		if (i != N - 1) printf(", ");
	}
	printf(">");
}

void make_que(Linked* q, int n)
{
	for (int i = 1; i <= n; i++)
	{
		Quenode* temp = (Quenode*)malloc(sizeof(Quenode));
		temp->data = i;
		temp->link = NULL;
		if (i == 1)
		{
			q->front = temp;
			q->rear = temp;
		}
		else if (i == n)
		{
			q->rear->link = temp;
			q->rear = temp;
			q->rear->link = q->front;
		}
		else
		{
			q->rear->link = temp;
			q->rear = temp;
		}
	}
}

int delete_que(Linked* q, int k)
{
	Quenode* tmp = q->front;
	int temp;
	for (int i = 0; i < k-1; i++)
	{
		q->rear = tmp;
		tmp = tmp->link;
	}
	temp = tmp->data;
	q->front = tmp->link;
	q->rear->link = q->front;
	free(tmp);
	return temp;
}