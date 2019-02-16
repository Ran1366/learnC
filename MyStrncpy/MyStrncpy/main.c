#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char * MyStrncpy(char * des, const char * src, size_t num)
{
	assert(des != NULL);
	assert(src != NULL);
	assert(num >= 0);
	size_t i;
	for (i = 0; i < num; ++i)
	{
		des[i] = src[i];
	}
	des[i] = '\0';
	return des;
}
int main()
{
	char s1[] = {"hello world"};
	char s2[30];
	char s3[30];
	MyStrncpy(s2, s1, sizeof(s1));
	printf("%s\n", s2);
	MyStrncpy(s3, s1, 7);
	printf("%s\n", s3);
	system("pause");
	return 0;
}