#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void IsLeapYear(int year)
{
	if (year % 400 == 0)
	{
		printf("������\n");
	}
	else if (year % 4 == 0 && year % 100 != 0)
	{
		printf("������\n");
	}
	else
	{
		printf("��������\n");
	}
}
int main()
{
	//ʵ��һ�������ж�year�ǲ�������
	int year = 0;
	scanf("%d", &year);
	IsLeapYear(year);
	system("pause");
	return 0;
}