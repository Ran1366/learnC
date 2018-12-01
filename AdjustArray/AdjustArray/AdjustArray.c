#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void AdjustArray(int *arr,int size)
{
	printf("here");
	int head = 0;				//定义表头初始值为0
	int tail = size - 1;		//定义表尾初始值为总长度-1
	int i = 0;
	int temp = 0;
	while (i < tail + 1)		//i只用增加到奇数的个数个就退出循环
	{
		if (arr[i] % 2 == 0)	//如果当前元素是偶数则将它放入表尾，并且
		{						//让表尾下标向前挪一个
			temp = arr[i];
			arr[i] = arr[tail];
			arr[tail] = temp;
			--tail;
		}
		if (arr[i] % 2 == 1)	//如果当前元素是奇数则让i自加1继续循环
		{
			++i;
		}
	}
}
int main()
{
	/*输入一个整数数组，实现一个函数，
	来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
	所有偶数位于数组的后半部分。*/
	int arr[] = {2,6,5,7,8};
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0 ; i < size ; ++i)
	{
		printf("%d ", arr[i]);
	}
	AdjustArray(arr,size);
	printf("\n");
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}