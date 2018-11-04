#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void isPrimeNum(int num)
{
	if(num == 1)printf("是素数\n");
	int i = 2;
	for (;i<num;i++)
	{
		if (num%i == 0)
		{
			printf("不是素数\n");
			break;
		}
	}
	if (i == num)
	{
		printf("是素数\n");
	}
}
int main()
{
	//实现一个函数，判断一个数是不是素数
	int num = 0;
	scanf("%d",&num);
	isPrimeNum(num);
	system("pause");
	return 0;
}