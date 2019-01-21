#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void rotat(char s[], int size, int k)
{
	if (size > 1)
	{
		int i = 0;
		char *_s = (char*)malloc(k);
		for (i = 0; i < k; ++i)
		{
			_s[i] = s[i];
		}
		for (i = 0; i < size - k; ++i)
		{
			s[i] = s[i + k];
		}
		for (i = 0; i < k; ++i)
		{
			s[size - k + i] = _s[i];
		}
	}
}
int main()
{
	// ʵ��һ�����������������ַ����е�k���ַ���                                                                                    
	// ABCD����һ���ַ��õ�BCDA 
	// ABCD���������ַ��õ�CDAB
	char s[] = "ABCDEFGHIJK";
	int size = sizeof(s) / sizeof(s[0]) - 1;
	printf("%s\n", s);
	rotat(s, size, 4);
	printf("%s\n", s);
	system("pause");
	return 0;
}