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
	/*дһ���������ز����������� 1 �ĸ���
		���磺 15 0000 1111 4 �� 1
		����ԭ�ͣ�
		int count_one_bits(unsigned int value)
	{
		// ���� 1��λ�� 
	}*/
	printf("%d\n",countBits(15));
	system("pause");
	return 0;
}