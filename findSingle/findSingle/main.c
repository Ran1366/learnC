#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void findSingle(int arr[], int size)
{
	//�������ÿһλ�������
	int i = 0;
	int result = 0;
	for (i = 0; i < size; ++i)
	{
		result ^= arr[i];
	}
	//���Ľ������
	//�ҵ�����Ķ��������г��ֵĵ�һ��1
	int locat = 0;
	for (i = 0; i < 32; ++i)
	{
		if (((result >> i) & 1) == 1)
		{
			locat = i;
			break;
		}
	}
	//�������λ�ð�����ֳ�����ֱ��ٴ����
	int x = 0;
	int y = 0;
	for (i = 0; i < size; ++i)
	{
		if (((arr[i] >> locat) & 1) == 1)
		{
			x ^= arr[i];
		}
		else
		{
			y ^= arr[i];
		}
	}
	//�õ�����Ҫ�ҵ�����                                                                                                           
	printf("ֻ���ֹ�һ�ε�����������%d,%d\n", x, y);
}

int main()
{
	//һ��������ֻ�����������ǳ���һ�Σ� 
	//  �����������ֶ����������Ρ� 
	//  �ҳ����������֣����ʵ�֡�
	int arr[] = { 1,2,3,2,3,4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	findSingle(arr, size);
	system("pause");
	return 0;
}