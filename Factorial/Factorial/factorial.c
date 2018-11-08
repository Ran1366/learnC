#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Factorial(int n)
{
	//递归实现
	if (n == 1)
	{
		return 1;
	}
	else 
	{
		return n * Factorial(n-1);
	}
}
int Factorial2(int n)
{
	//非递归实现
	int result = 1;
	for (int i = 1;i<=n;i++)
	{
		result = result * i;
	}
	return result;
}
int main()
{
	printf("%d\n",Factorial(5));
	printf("%d\n", Factorial2(5));
	system("pause");
	return 0;
}