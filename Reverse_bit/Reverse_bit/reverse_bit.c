#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	unsigned int temp = 0;
	unsigned int sum = 0;
	while (i < 32)
	{
		temp = value % 2;
		sum += (temp << (31 - i));
		value /= 2;
		++i;
	}
	return sum;
}
int main()
{
	/*编写函数：
		unsigned int reverse_bit(unsigned int value);
	这个函数的返回值value的二进制位模式从左到右翻转后的值。

		如：
		在32位机器上25这个值包含下列各位：
		00000000000000000000000000011001
		翻转后：（2550136832）
		10011000000000000000000000000000
		程序结果返回：
		2550136832*/
	printf("%u", reverse_bit(25));
	system("pause");
	return 0;
}