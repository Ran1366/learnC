#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int DigitSum(int num)
{
	
	if (num < 0)
	{
		printf("输入错误");
		return -1;
	}
	if (num < 10)
	{
		return num;
	}
	return num % 10 + DigitSum(num / 10);
}
int main()
{
	//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和， 
	//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
	printf("%d\n",DigitSum(1234));
	system("pause");
	return 0;
}