#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int MyPower(int n,int k)
{
	if (k > 0)
	{
		return n * MyPower(n, k - 1);
	}
	return 1;
}
int main()
{
	//编写一个函数实现n^k，使用递归实现 
	printf("%d\n", MyPower(6, 3));
	system("pause");
	return 0;
}