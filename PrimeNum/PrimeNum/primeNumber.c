#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void isPrimeNum(int num)
{
	if(num == 1)printf("������\n");
	int i = 2;
	for (;i<num;i++)
	{
		if (num%i == 0)
		{
			printf("��������\n");
			break;
		}
	}
	if (i == num)
	{
		printf("������\n");
	}
}
int main()
{
	//ʵ��һ���������ж�һ�����ǲ�������
	int num = 0;
	scanf("%d",&num);
	isPrimeNum(num);
	system("pause");
	return 0;
}