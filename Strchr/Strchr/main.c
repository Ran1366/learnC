#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

const char * Strchr(const char * str, int character)
{
	assert(str != NULL);
	assert(character >= 0);
	int i = 0;
	while (str[i] != '\0')
	{
		if (character == str[i])
		{
			return str + i;
		}
		if (character != str[i])
		{
			++i;
		}
	}
	return NULL;
}
int main()
{
	char str[] = "hello world";
	char c = 'w';
	int locat = Strchr(str, c) - str;
	printf("第一个出现字符%c的位置是%d\n", c,locat + 1);
	system("pause");
	return 0;
}