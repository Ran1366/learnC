#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void FindSingle(int * a,int a_size)
{
	for (int i = 0;i < a_size;++i)
	{
		int re = 0;
		for (int j = 0;j < a_size;++j)
		{
			if ((a[i] ^ a[j]) == 0)
			{
				++re;
			}
		}
		if (re == 1)
		{
			printf("��Ԫ�ص�ֵ��%d,�±���%d\n", a[i], i);
			break;
		}
	}
}
int main()
{
	/*���ʵ�֣�
		һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
		���ҳ�������֡���ʹ��λ���㣩*/
	int a[] = {3,3,5,7,9,5,1,7,9};
	FindSingle(a,sizeof(a)/sizeof(a[0]));
	system("pause");
	return 0;
}