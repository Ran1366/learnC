#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Mutiplication(int n)
{
	for (int i =1;i<n+1;i++)
	{
		for (int j =1;j<i+1;j++)
		{
			printf("%d x %d = %d\t",j,i,j*i);
		}
		printf("\n");
	}
}
int main()
{
	//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ���� 
	//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
	printf("���Լ��ƶ�Ҫ��ӡ�ĳ˷��ھ��������������\n");
	int n = 0;
	scanf("%d",&n);
	Mutiplication(n);
	system("pause");
	return 0;
}