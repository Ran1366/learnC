#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Parity(int num)
{
	printf("ż��λ��");
	for (int i = 31 ; i > -1 ; i -= 2)
	{
		printf("%d ", (num >> i) & 0x1);
	}
	printf("\n����λ��");
	for (int i = 30 ; i > -1 ; i -= 2)
	{
		printf("%d ", (num >> i) & 0x1);
	}
}
int main()
{
	/*.��ȡһ�������������������е�ż��λ������λ��
		�ֱ�������������С�*/
	Parity(5);
	system("pause");
	return 0;
}