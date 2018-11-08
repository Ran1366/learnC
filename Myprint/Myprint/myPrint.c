#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void MyPrint(int n)
{
	if (n > 9)
	{
		MyPrint(n / 10);
	}
	printf("%d\t", n % 10);
}
int main()
{
	MyPrint(5648);
	system("pause");
	return 0;
}