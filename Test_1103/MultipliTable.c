#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Mutiplication(int n)
{
	for (int i =1;i<n+1;i++)
	{
		for (int j =1;j<i+1;j++)
		{
			printf("%d x %d = %d\t",j,i,j*i);
		}
		printf("\n");
	}
}
int main()
{
	//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定， 
	//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
	printf("请自己制定要打印的乘法口诀表的行数和列数\n");
	int n = 0;
	scanf("%d",&n);
	Mutiplication(n);
	system("pause");
	return 0;
}