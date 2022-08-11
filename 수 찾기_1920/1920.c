#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void quicksort(int arr[], int L, int R)
{
	int left = L, right = R;
	int pivot = arr[(L + R) / 2];
	int temp;
	do
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	} while (left <= right);
	if (L < right)
		quicksort(arr, L, right);
	if (left < R)
		quicksort(arr, left, R);
}

int binarysearch(int arr[], int size, int num)
{
	int front, mid, rear;
	front = 0;
	rear = size;
	while (1)
	{
		mid = (front + rear) / 2;
		if (arr[mid] == num) return 1;
		if (arr[front] == num) return 1;
		if (arr[rear] == num) return 1;
		if (arr[mid] < num) front = mid + 1;
		else rear = mid - 1;
		if (rear <= front) return 0;
	}

}


int main()
{
	int N, M;
	int i;

	scanf("%d", &N);
	int A[100000];
	for (i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	quicksort(A, 0, N - 1);
	scanf("%d", &M);
	int B;
	for (i = 0; i < M; i++)
	{
		scanf("%d", &B);
		printf("%d\n", binarysearch(A, N - 1, B));
	}

}
