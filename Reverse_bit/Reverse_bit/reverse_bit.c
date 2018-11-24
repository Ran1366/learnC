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
	/*��д������
		unsigned int reverse_bit(unsigned int value);
	��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��

		�磺
		��32λ������25���ֵ�������и�λ��
		00000000000000000000000000011001
		��ת�󣺣�2550136832��
		10011000000000000000000000000000
		���������أ�
		2550136832*/
	printf("%u", reverse_bit(25));
	system("pause");
	return 0;
}