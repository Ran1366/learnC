#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void IntegerBinary(int num)
{
	printf("�������Ķ����Ʊ�ʾ��");
	for (int i = 31 ; i > -1 ; i--)
	{
		printf("%d",(num >> i) & 0x1);
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
}
int main()
{
	//���һ��������ÿһλ
	IntegerBinary(5);
	system("pause");
	return 0;
}