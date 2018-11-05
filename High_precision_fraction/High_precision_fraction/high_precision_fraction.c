#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Fraction(int dividend,int divisor)
{
	int i = 0;
	int arrays[200];
	if (dividend < divisor)
	{
		for (; i < 200; i++)
		{
			arrays[i] = (dividend * 10) / divisor;
			if ((dividend * 10) % divisor == 0)
			{
				break;
			}
			dividend = (dividend * 10) % divisor;
		}
		printf("0.");
		for (int j = 0; j < i + 1; j++)
		{
			printf("%d", arrays[j]);
		}
		printf("\n");
	}
	else 
	{
		printf("输入错误，被除数要小于除数");
	}
}
int main()
{
	Fraction(16,29);
	system("pause");
	return 0;
}