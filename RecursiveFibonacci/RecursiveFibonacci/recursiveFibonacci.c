#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int RecursiveFib(int n)
{
	//�ݹ鷨���n��쳲�������
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
	//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
	printf("%d\n",NoReFib(55));
	system("pause");
	return 0;
}