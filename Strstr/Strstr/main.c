#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

const char * Strstr(const char * str1, const char * str2)
{
	int i_str1 = 0;
	int i_str2 = 0;
	char * locat = NULL;
	//ɨ���ַ���1ֱ��'\0'
	while (str1[i_str1] != '\0')
	{
		if (str2[i_str2] != str1[i_str1]) 
		{
			//����ַ���2�е�һ�������ַ��������ַ���1�е�һ���ַ�
			//�����ַ���2��ɨ��λ�ûָ��������ַ���
			if (i_str2 != 0)
			{
				i_str2 = 0;
			}
			//�����ַ���1��ɨ��λ�ü�һ
			else
			{
				++i_str1;
			}
		}
		if (str2[i_str2] == str1[i_str1])
		{
			//��¼�ַ���2��Ԫ�ص�һ�����ַ���1���ַ���ȵ�λ��
			if (i_str2 == 0)
			{
				locat = str1 + i_str1;
			}
			++i_str1;
			++i_str2;
			if (str2[i_str2] == '\0')
			{
				return locat;
			}
		}
	}
	return NULL;
}
int main()
{
	const char str1[] = "hello woworld nihao";
	const char str2[] = "wreld";
	const char str3[] = "world";
	printf("%s\n", Strstr(str1, str2));
	printf("%s\n", Strstr(str1, str3));
	system("pause");
	return 0;
}