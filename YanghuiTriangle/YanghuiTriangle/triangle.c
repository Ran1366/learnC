#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int triangle[100][100];
void Yanghui(int n)
{
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < i + 1 ; j++)
		{
			if (j == 0 || j == i)
			{
				triangle[i][j] = 1;
				printf("%d ", triangle[i][j]);
			}
			else 
			{
				triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
				printf("%d ", triangle[i][j]);
			}
		}
		printf("\n");

	}
}
int main()
{
	/*在屏幕上打印杨辉三角。
		1
		1 1
		1 2 1
		1 3 3 1*/
	Yanghui(6);
	system("pause");
	return 0;
}