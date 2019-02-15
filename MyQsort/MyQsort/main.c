#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int(*T)(int,int);
//规定T运算后符合排序要求返回0,不符合则返回1,

int ascend(int before , int after)
{
	return (before < after) ? 0 : 1;
}
int descend(int before, int after)
{
	return (before > after) ? 0 : 1;
}
MyQsort(int arr[], int size, T rules)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (rules(arr[j], arr[j + 1]))
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
Print(int arr[], int size)
{
	int i = 0;
	while (i < size)
	{
		printf("%d ",arr[i]);
		++i;
	}
	printf("\n");
}
int main()
{
	int arr[] = { 6,8,5,4,2,3,1 };
	Print(arr, 7);
	MyQsort(arr,7,ascend);
	Print(arr, 7);
	MyQsort(arr, 7, descend);
	Print(arr, 7);
	system("pause");
	return 0;
}