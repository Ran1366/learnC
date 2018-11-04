#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void IsLeapYear(int year)
{
	if (year % 400 == 0)
	{
		printf("是闰年\n");
	}
	else if (year % 4 == 0 && year % 100 != 0)
	{
		printf("是闰年\n");
	}
	else
	{
		printf("不是闰年\n");
	}
}
int main()
{
	//实现一个函数判断year是不是润年
	int year = 0;
	scanf("%d", &year);
	IsLeapYear(year);
	system("pause");
	return 0;
}