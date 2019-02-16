#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int MyStrncmp(const char * str1, const char * str2, size_t num)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	assert(num >= 0);
	size_t i = 0;
	int result = 0;
	while (i < num)
	{
		result = str1[i] - str2[i];
		++i;
		if (result != 0)
		{
			break;
		}
	}
	return result;
}
int main()
{
	char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
	int n;
	puts("Looking for R2 astromech droids...");
	for (n = 0; n < 3; n++)
		if (MyStrncmp(str[n], "R2xx", 2) == 0)
		{
			printf("found %s\n", str[n]);
		}
	system("pause");
	return 0;
}