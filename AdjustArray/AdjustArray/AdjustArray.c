#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void AdjustArray(int *arr,int size)
{
	printf("here");
	int head = 0;				//�����ͷ��ʼֵΪ0
	int tail = size - 1;		//�����β��ʼֵΪ�ܳ���-1
	int i = 0;
	int temp = 0;
	while (i < tail + 1)		//iֻ�����ӵ������ĸ��������˳�ѭ��
	{
		if (arr[i] % 2 == 0)	//�����ǰԪ����ż�����������β������
		{						//�ñ�β�±���ǰŲһ��
			temp = arr[i];
			arr[i] = arr[tail];
			arr[tail] = temp;
			--tail;
		}
		if (arr[i] % 2 == 1)	//�����ǰԪ������������i�Լ�1����ѭ��
		{
			++i;
		}
	}
}
int main()
{
	/*����һ���������飬ʵ��һ��������
	�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
	����ż��λ������ĺ�벿�֡�*/
	int arr[] = {2,6,5,7,8};
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0 ; i < size ; ++i)
	{
		printf("%d ", arr[i]);
	}
	AdjustArray(arr,size);
	printf("\n");
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}