#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isfind;
void Serch(int arr[3][3],int num)
{
	int x = 0;
	int y = 2;
	while (x >= 0 && x < 3 && y >=0 && y < 3)
	{					
		if (num > arr[x][y])//�������Ͻǵ����Ƚϣ�������ˣ��ͱȽ���һ��
		{
			++x;
		}
		if (num < arr[x][y])//���С�ˣ��ͱȽ�ǰһ��
		{
			--y;
		}
		if (num == arr[x][y])//���������ҵ���
		{
			printf("�ҵ��ˣ��±��ǣ�%d %d\n",x,y);
			break;
		}
	}
	if (!(x >= 0 && x < 3 && y >= 0 && y < 3))//����Խ����û�ҵ�
	{
		printf("û�ҵ�\n");
	}
}
int main()
{
	/*��һ����ά����.
	�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
	�������������в���һ�������Ƿ���ڡ�
	ʱ�临�Ӷ�С��O(N);*/
	int arr[3][3] = 
	{
		{1,5,7},
		{2,6,9},
		{4,8,11},
	};
	Serch(arr,4);
	system("pause");
	return 0;
}