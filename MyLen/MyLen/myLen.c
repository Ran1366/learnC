#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Mylen(char * s)
{
	//非递归实现
	int i = 0;
	while (*(s+i))
	{
		i++;
	}
	return printf("%d\n",i);
}
void len(char * s,int i)
{
	//递归实现
	if (*(s + i))
	{
		i++;
		len(s, i);
	}
	else 
	{
		printf("%d\n", i);
	}
	
}
void My_len(char *s)
{
	int  i = 0;
	len(s,i);
}
int main()
{
	char *s = "abcedfg";
	Mylen(s);
	My_len(s);
	system("pause");
	return 0;
}