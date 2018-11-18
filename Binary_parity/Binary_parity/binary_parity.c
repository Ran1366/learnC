#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Parity(int num)
{
	printf("偶数位：");
	for (int i = 31 ; i > -1 ; i -= 2)
	{
		printf("%d ", (num >> i) & 0x1);
	}
	printf("\n奇数位：");
	for (int i = 30 ; i > -1 ; i -= 2)
	{
		printf("%d ", (num >> i) & 0x1);
	}
}
int main()
{
	/*.获取一个数二进制序列中所有的偶数位和奇数位，
		分别输出二进制序列。*/
	Parity(5);
	system("pause");
	return 0;
}