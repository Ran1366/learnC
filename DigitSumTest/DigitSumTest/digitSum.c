#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int DigitSum(int num)
{
	
	if (num < 0)
	{
		printf("�������");
		return -1;
	}
	if (num < 10)
	{
		return num;
	}
	return num % 10 + DigitSum(num / 10);
}
int main()
{
	//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ� 
	//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
	printf("%d\n",DigitSum(1234));
	system("pause");
	return 0;
}