#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
	int* data;
	char res[100000];
	int num;
	int size;
}Stack;

void push(Stack*, int);
void pop(Stack*);

int main()
{
	Stack stack;
	stack.data = (int*)malloc(sizeof(int)*100000);
	stack.size = 0;
	stack.num = 0;
	int n;
	int i, j;
	scanf("%d", &n);
	if (n < 1 || n>100000) exit(0);		//n의 범위가 (1 ≤ n ≤ 100,000)아닐 시 exit
	int arr[100000];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int count = 1;
	for (i = 0; i < n; i++)
	{
		if (stack.data[stack.size - 1] == arr[i])
		{
			pop(&stack);
		}
		else
		{
			while (count != arr[i])
			{
				push(&stack, count);
				count++;
				if (count > n)
				{
					printf("NO");
					exit(0);
				}
			}
			push(&stack, count);
			count++;
			pop(&stack);
		}
	}
	for (i = 0; i < stack.num; i++)
	{
		printf("%c\n", stack.res[i]);
	}
}

void push(Stack* st, int num)
{
	st->data[st->size++] = num;
	st->res[st->num++] =  '+';
}

void pop(Stack* st)
{
	st->data[--st->size]==0;
	st->res[st->num++] = '-';
}