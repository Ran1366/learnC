#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int countBits(unsigned int num)
{
	int coust = 0;
		while (num % 2 == 1 || num % 2 == -1)
		{
			coust++;
			num = num / 2;
		}
	return coust;
}
int main()
{
	/*写一个函数返回参数二进制中 1 的个数
		比如： 15 0000 1111 4 个 1
		程序原型：
		int count_one_bits(unsigned int value)
	{
		// 返回 1的位数 
	}*/
	printf("%d\n",countBits(15));
	system("pause");
	return 0;
}