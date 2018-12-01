#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isfind;
void Serch(int arr[3][3],int num)
{
	int x = 0;
	int y = 2;
	while (x >= 0 && x < 3 && y >=0 && y < 3)
	{					
		if (num > arr[x][y])//先与右上角的数比较，如果大了，就比较下一行
		{
			++x;
		}
		if (num < arr[x][y])//如果小了，就比较前一列
		{
			--y;
		}
		if (num == arr[x][y])//相等则输出找到了
		{
			printf("找到了，下标是：%d %d\n",x,y);
			break;
		}
	}
	if (!(x >= 0 && x < 3 && y >= 0 && y < 3))//数组越界则没找到
	{
		printf("没找到\n");
	}
}
int main()
{
	/*有一个二维数组.
	数组的每行从左到右是递增的，每列从上到下是递增的.
	在这样的数组中查找一个数字是否存在。
	时间复杂度小于O(N);*/
	int arr[3][3] = 
	{
		{1,5,7},
		{2,6,9},
		{4,8,11},
	};
	Serch(arr,4);
	system("pause");
	return 0;
}