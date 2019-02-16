#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
char * MyStrncat(char * des, const char * src, size_t num)
{
	assert(des != NULL);
	assert(src != NULL);
	assert(num >= 0);
	size_t i = 0;
	size_t j = 0;
	while (des[i] != '\0') { ++i; };	
	for (; j < num; ++j)
	{
		des[i] = src[j];
		++i;
	}
	des[i] = '\0';
	return des;
}
int main()
{
	char s2[] = "hello";
	char s3[20] = "world";
	MyStrncat(s3, s2, sizeof(s2));
	printf("%s\n",s3);
	system("pause");
	return 0;
}