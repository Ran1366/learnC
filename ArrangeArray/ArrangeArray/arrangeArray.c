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
	//编写一个函数 reverse_string(char * string)（递归实现） 
	//实现：将参数字符串中的字符反向排列。
	//要求：不能使用C函数库中的字符串操作函数
	char s[]= "abcd";
	reverse_string(s);
	system("pause");
	return 0;
}