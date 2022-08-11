#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
	int key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* search(TreeNode* node, int key);
TreeNode* insert(TreeNode* node, int key);
TreeNode* new_node(int data);


int main()
{
	int N, M;
	int i;
	TreeNode* root=NULL;
	scanf("%d", &N);
	if (N < 1 || N>100000)
	{
		printf("error\n");
		exit(0);
	}
	int A[100000];		//처음 N개의 숫자를 입력받을 배열
	int B[100000];		//그 다음 탐색할 숫자 M개를 입력받을 배열
	for (i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		root= insert(root, A[i]);			//이진탐색 트리에 삽입
	}
	
	while (getchar() != '\n');
	scanf("%d", &M);
	if (M < 1 || M>100000)
	{
		printf("error\n");
		exit(0);
	}
	for (i = 0; i < M; i++)
	{
		scanf("%d", &B[i]);
		if (search(root, B[i]) == NULL)
		{
			printf("0\n");
		}
		else
		{
			printf("1\n");
		}
	}
	while (getchar() != '\n');

}


TreeNode* search(TreeNode* node, int key)
{
	while (node != NULL)		//노드가 널이면 반복 종료
	{
		if (key == node->key)		//찾는 숫자였으면 node주소 반환
		{
			return node;
		}
		else if (key > node->key)		//찾는 숫자보다 지금 노드가 작으면 노드의 주소를 지금 노드의 오른쪽으로 넘김
		{
			node = node->right;
		}
		else
		{
			node = node->left;		//찾는 숫자보다 지금 노드가 크면 노드의 주소를 지금 노드의 왼쪽으로 넘김
		}
	}
	return NULL;		//탐색하지 못했으면 널 반환
}

TreeNode* insert(TreeNode* node, int key)
{
	if (node == NULL)		//노드가 아무것도 없을 경우
	{
		return new_node(key);		//새로운 노드를 생성해준다.
	}
	else if (node->key > key)		//새로 들어온 값이 지금 노드보다 값이 작은경우
	{
		node->left = insert(node->left, key);		//순환함수로 left로 이동
	}
	else		//새로 들어온 값이 지금 노드보다 값이 큰경우
	{
		node->right = insert(node->right, key);		//순환함수로 right로 이동
	}
	return node;		//node주소값 반환
}

TreeNode* new_node(int data)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}