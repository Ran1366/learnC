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
	//Ԫ����β����ʵ�ֵ���
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
	printf("��ѡ��1.�������2.���鵹��\n");
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
	//����һ�����飬 
	//ʵ�ֺ���init������ʼ�����顢
	//ʵ��empty����������顢
	//ʵ��reverse���������������Ԫ�ص����á�
	//Ҫ���Լ���ƺ����Ĳ���������ֵ��
	int a[5];
	int n = sizeof(a) / sizeof(a[0]);
	init(a, n);
	showArray(a,n);
	operaArray(a,n);
	system("pause");
	return 0;
}