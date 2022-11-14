#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
	int* data;
	int size;
}Stack;

void push(Stack*, int a);
void print(Stack* s);
int pop(Stack* s);

int main()
{
	int T, i, j;
	Stack st;
	st.size = 0;
	st.data = calloc(51, sizeof(int));
	char input[51];
	scanf("%d", &T);		//몇번 물은건지 확인
	for (i = 0; i < T; i++)
	{
		st.size = 0;
		int error = 0;
		scanf("%s", &input);		//문자열 입력
		for (j = 0; j < strlen(input); j++)		
		{
			if (input[j] == '(')
			{
				push(&st, 1);
			}
			else if (input[j] == ')')
			{
				if (pop(&st) == -1 )		//스택이 비어있으면
				{
					error++;
				}
			}
		}
		if (j == strlen(input) && st.size > 0)
			error++;

		if (error != 0)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}

void push(Stack* s, int a)
{
	s->data[s->size++] = a;
}

int pop(Stack* s)
{
	if (s->size == 0)		//스택이 비어있으면 
	{
		s->size--;
		return -1;
	}
	else			//스택이 비어있지 않으면
	{
		s->size--;
		return 0;
	}
		
}

void print(Stack* s)
{
	int i = 0;
	for (i = 0; i < s->size; i++)
	{
		printf("%d", s->data[i]);
	}
}