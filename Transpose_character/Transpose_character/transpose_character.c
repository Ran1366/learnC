#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void TransChar(char s[],int s_size)
{
	if (s_size > 1)
	{
		for (int i = 0; i < s_size / 2; ++i)
		{
			char temp = s[i];
			s[i] = s[s_size - i - 1];
			s[s_size - i - 1] = temp;
		}
	}
}
void TTchar(char s[],int s_size)
{
	TransChar(s,s_size - 1);
	int head = 0;
	for (int i = 0 ; i < s_size ; ++i)
	{
		if (s[i] == ' '|| i == s_size -1)
		{
			TransChar(s+head, i - head);
			head = i + 1;
		}
	}
}
int main()
{
	/*��һ���ַ����������Ϊ:"student a am i",
	���㽫��������ݸ�Ϊ"i am a student".
	Ҫ��
	����ʹ�ÿ⺯����
	ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

	student a am i
	i ma a tneduts
	i am a student*/
	//char s[] = "student a am i";
	char s[] = "student a am i";
	TTchar(s,sizeof(s)/sizeof(s[0]));
	for (int i = 0; i < sizeof(s) / sizeof(s[0]); ++i)
	{
		printf("%c",s[i]);
	}
	system("pause");
	return 0;
}