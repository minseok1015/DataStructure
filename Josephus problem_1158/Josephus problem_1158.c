#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Que
{
	int size;
	int* data;
	int count;
}Que;

int delete(Que*);
void make_que(Que*,int);

int main()
{
	int N, K;
	scanf("%d", &N);
	scanf("%d", &K);
	if (K > N) exit(0);		// (1 ≤ K ≤ N ≤ 5,000) 조건을 위한 에러처리
	Que que;
	que.size = 1;
	que.data = (int*)malloc(sizeof(int) * 5000);
	que.count = N;
	make_que(&que,N);
	printf("< ");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", delete(&que,K));
	}
	printf(">");
}

int delete(Que* que,int k)
{
	que->count = (que->count + k) % (que->size-1);
	return que->data[que->count];
}

void make_que(Que* que,int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		que->data[que->size++]=i;
	}
}