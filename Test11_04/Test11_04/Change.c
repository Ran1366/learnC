#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void exchan(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	//ʹ�ú���ʵ���������Ľ���
	int a = 5;
	int b = 10;
	exchan(&a, &b);
	printf("a = %d,b = %d", a, b);
	system("pause");
	return 0;
}