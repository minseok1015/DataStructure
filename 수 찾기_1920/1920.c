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
	int A[100000];		//ó�� N���� ���ڸ� �Է¹��� �迭
	int B[100000];		//�� ���� Ž���� ���� M���� �Է¹��� �迭
	for (i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		root= insert(root, A[i]);			//����Ž�� Ʈ���� ����
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
	while (node != NULL)		//��尡 ���̸� �ݺ� ����
	{
		if (key == node->key)		//ã�� ���ڿ����� node�ּ� ��ȯ
		{
			return node;
		}
		else if (key > node->key)		//ã�� ���ں��� ���� ��尡 ������ ����� �ּҸ� ���� ����� ���������� �ѱ�
		{
			node = node->right;
		}
		else
		{
			node = node->left;		//ã�� ���ں��� ���� ��尡 ũ�� ����� �ּҸ� ���� ����� �������� �ѱ�
		}
	}
	return NULL;		//Ž������ �������� �� ��ȯ
}

TreeNode* insert(TreeNode* node, int key)
{
	if (node == NULL)		//��尡 �ƹ��͵� ���� ���
	{
		return new_node(key);		//���ο� ��带 �������ش�.
	}
	else if (node->key > key)		//���� ���� ���� ���� ��庸�� ���� �������
	{
		node->left = insert(node->left, key);		//��ȯ�Լ��� left�� �̵�
	}
	else		//���� ���� ���� ���� ��庸�� ���� ū���
	{
		node->right = insert(node->right, key);		//��ȯ�Լ��� right�� �̵�
	}
	return node;		//node�ּҰ� ��ȯ
}

TreeNode* new_node(int data)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}