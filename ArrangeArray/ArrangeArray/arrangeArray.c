#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int MyLen(char s[])
{
	int i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return i;
}
void reverse(char *s,int start,int len)
{
	if (start >= len)
	{
		printf("%s", s);
	}
	else 
	{
		int temp = *(s + start);
		*(s + start) = *(s + len);
		*(s + len) = temp;
		reverse(s,++start,--len);
	}
		
}
void reverse_string(char * s)
{
	int len = MyLen(s)-1;
	int start = 0;
	reverse(s,start,len);
}

int main()
{
	//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣� 
	//ʵ�֣��������ַ����е��ַ��������С�
	//Ҫ�󣺲���ʹ��C�������е��ַ�����������
	char s[]= "abcd";
	reverse_string(s);
	system("pause");
	return 0;
}