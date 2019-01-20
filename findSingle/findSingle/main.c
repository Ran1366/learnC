#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void findSingle(int arr[], int size)
{
	//把数组的每一位都做异或
	int i = 0;
	int result = 0;
	for (i = 0; i < size; ++i)
	{
		result ^= arr[i];
	}
	//异或的结果保存
	//找到结果的二进制码中出现的第一个1
	int locat = 0;
	for (i = 0; i < 32; ++i)
	{
		if (((result >> i) & 1) == 1)
		{
			locat = i;
			break;
		}
	}
	//根据这个位置把数组分成两组分别再次异或
	int x = 0;
	int y = 0;
	for (i = 0; i < size; ++i)
	{
		if (((arr[i] >> locat) & 1) == 1)
		{
			x ^= arr[i];
		}
		else
		{
			y ^= arr[i];
		}
	}
	//得到最终要找的数字                                                                                                           
	printf("只出现过一次的两个数字是%d,%d\n", x, y);
}

int main()
{
	//一个数组中只有两个数字是出现一次， 
	//  其他所有数字都出现了两次。 
	//  找出这两个数字，编程实现。
	int arr[] = { 1,2,3,2,3,4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	findSingle(arr, size);
	system("pause");
	return 0;
}