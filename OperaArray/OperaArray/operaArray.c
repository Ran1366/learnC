#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void init(int a[],int n)
{
	for (int i = 0;i < n;i++)
	{
		a[i] = i * i + 1;
	}
}
void empty(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
	}
}
void reverse(int a[],int n)
{
	int temp = 0;
	//元素首尾交换实现倒置
	for (int i = 0; i < n/2; i++)
	{
		temp = a[n - i - 1];
		a[n - i - 1] = a[i];
		a[i] = temp;
	}
}
void showArray(int a[],int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t",a[i]);
	}
}
int menu()
{
	int input = 0;
	printf("请选择1.清空数组2.数组倒置\n");
	scanf("%d", &input);
	return input == 1 ? 1 : 2;
}
void operaArray(int a[],int n)
{
	if (menu() == 1)
	{
		empty(a, n);
		showArray(a, n);
	}
	else
	{
		reverse(a, n);
		showArray(a, n);
	}
}
int main()
{
	//创建一个数组， 
	//实现函数init（）初始化数组、
	//实现empty（）清空数组、
	//实现reverse（）函数完成数组元素的逆置。
	//要求：自己设计函数的参数，返回值。
	int a[5];
	int n = sizeof(a) / sizeof(a[0]);
	init(a, n);
	showArray(a,n);
	operaArray(a,n);
	system("pause");
	return 0;
}