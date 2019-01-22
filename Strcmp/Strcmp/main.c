#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int strcmp(const char * str1, const char * str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	int i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] - str2[i] > 0)
		{
			return str1[i] - str2[i];
		}
		else if (str1[i] - str2[i] < 0)
		{
			return str1[i] - str2[i];
		}
		else 
		{
			++i;
		}
	}
	if (str1[i] == '\0' && str2[i] != '\0')
	{
		return -str2[i];
	}
	if (str1[i] != '\0' && str2[i] == '\0')
	{
		return str1[i];
	}
	if (str1[i] == '\0' && str2[i] == '\0')
	{
		return 0;
	}
}
int main()
{
	char str1[] = "acc";
	char str2[] = "abc";
	printf("%d\n", strcmp(str2, str1));
	system("pause");
	return 0;
}