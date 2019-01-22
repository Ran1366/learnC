#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void * Memcpy(void * dest, const void * src, size_t num)
{
	assert(dest != NULL);
	assert(src != NULL);
	assert(num >= 0);
	int i = 0;
	char *pdest = (char *)dest;
	char *psrc = (char *)src;
	for (i = 0; i < num; ++i)
	{
		pdest[i] = psrc[i];
	}
	return dest;
}
int main()
{
	int a[] = { 1,2,3,4 };
	int b[4] = { 5,6 };
	Memcpy(b, a, 12);
	for (int i = 0; i < 4; ++i)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}