#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char a[5];
	//b��һ������ָ��,��ָ��ָ��һ������5��Ԫ�ص�����
	char(*b)[5] = &a;
	printf("%p\n", b);
	printf("%p\n", &a);



	//����һ��ָ������
	//�������ÿһ��Ԫ�ض����ַ���,������ָ������������
	//char *b[5] = { "aaa","bbb","ccc","ddd","eee" };
	
















	//int a = 10;
	//int *pa = &a;//ȡa�ĵ�ַ������ָ��pa
	//int **ppa = &pa;//ȡһ��ָ��pa�ĵ�ַ����������ָ��ppa
	////������������䶼��ӡa�ĵ�ַ
	//printf("%p\n", &a);//��ӡa�ĵ�ַ
	//printf("%p\n", pa);//��ӡpa������
	//printf("%p\n\n", *ppa);//��ӡppa�����ú������
	////������������䶼��ӡpa�ĵ�ַ
	//printf("%p\n", &pa);//��ӡpa�ĵ�ַ
	//printf("%p\n\n",ppa);//��ӡppa������
	////������������䶼��ӡ10
	//printf("%d\n", a);
	//printf("%d\n",*pa);//*�����õõ�a,��ʱ*pa����a
	////ppa���ν����õõ�a,��һ�ν����õõ�pa������,Ҳ����a�ĵ�ַ
	////�ڶ��ν����õõ�a������,Ҳ����10
	//printf("%d\n", *(*ppa));
	system("pause");
	return 0;
}