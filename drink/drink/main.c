#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int drinkWater(int money)
{
	assert(money > 0);
	int wnum = 0;//�ȵ���������
	int bnum = 0;//��ƿ������
	int i = 0;
	for (i = 1; i <= money; ++i)
	{
		++wnum;
		++bnum;
		if (bnum == 2)//ÿ������ƿ��һƿ����
		{
			++wnum;
			bnum = 1;
		}
	}
	return wnum;
}
int main()
{
	//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ�� 
	//��20Ԫ�����Զ�����ˮ�� 
	int money = 20;
	int num = drinkWater(money);
	printf("%dԪ,���Ժ�%dƿ����\n", money, num);

	system("pause");
	return 0;
}