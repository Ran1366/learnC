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
	//扫描字符串1直到'\0'
	while (str1[i_str1] != '\0')
	{
		if (str2[i_str2] != str1[i_str1]) 
		{
			//如果字符串2中的一个非首字符不等于字符串1中的一个字符
			//则让字符串2的扫描位置恢复到其首字符处
			if (i_str2 != 0)
			{
				i_str2 = 0;
			}
			//否则字符串1的扫描位置加一
			else
			{
				++i_str1;
			}
		}
		if (str2[i_str2] == str1[i_str1])
		{
			//记录字符串2首元素第一次与字符串1中字符相等的位置
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