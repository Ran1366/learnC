#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void rotat(char s[], int size)
{
	if (size > 1)
	{
		int i = 0;
		char _s;
		_s = s[0];
		for (i = 0; i < size - 1; ++i)
		{
			s[i] = s[i + 1];
		}
		s[size - 1] = _s;
	}
}
int judeRotat(char s1[], char s2[], int size1, int size2)
{
	char* _s1 = (char*)malloc(size1);
	strcpy(_s1, s1);
	if (size1 == size2)
	{
		int count = size1;
		while (count > 0)
		{
			rotat(_s1, size1);
			--count;
			if (strcmp(_s1, s2) == 0)
			{
				break;
				free(_s1);
			}
		}
		if (count > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}
int main()
{
	//  �ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ����� 
	//  ���磺����s1 =AABCD��s2 = BCDAA������1������s1=abcd��s2=ACBD������0.  
	char s1[] = "AABCD";
	char s2[] = "BCDAA";
	int size1 = sizeof(s1) / sizeof(s1[0]) - 1;
	int size2 = sizeof(s2) / sizeof(s2[0]) - 1;
	int re = judeRotat(s1, s2, size1, size2);
	printf("%d\n", re);
	system("pause");
	return 0;
}