#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int RecursiveFib(int n)
{
	//递归法求第n个斐波那契数
	return (n < 2) ? n : RecursiveFib(n - 1) + RecursiveFib(n - 2);
}
int NoReFib(int n)
{
	int before = 1;
	int after = 1;
	int num = 0;
	while(n > 0)
	{
		before = after;
		after = num;
		num = after + before;
		n--;
	}
	return num;
}
int main()
{
	//递归和非递归分别实现求第n个斐波那契数
	printf("%d\n",NoReFib(55));
	system("pause");
	return 0;
}