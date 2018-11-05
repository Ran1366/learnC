#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
__int64 fib(int n)
{
	//��Ҫ����������L��߷����ֵ��R�ұ߷����ֵ
	//sum ��ǰ̨�׷���ֵ֮��
	__int64 R = 0;
	__int64 L = 1;
	__int64 sum = 0;
	for (int i = 0; i < n - 1; i++)
	{
		R = L;
		L = sum;
		sum = L + R;
	}
	return sum;
}
int main()
{
	int i = 1;
	long t = 1000000000L;
	clock_t start, finish;
	double useTime;
	start = clock();
	while (i < 92)
	{
		printf("��%d�%I64d\n", i , fib(i));
		i++;
	}
	finish = clock();
	useTime = (finish - start) / CLOCKS_PER_SEC;
	printf("���������ʱ%f��\n", useTime);
	system("pause");
	return 0;
}