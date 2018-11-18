#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpBinary(int m,int n)
{
	int counts = 0;
	for (int i = 31 ; i > -1 ; i--)
	{
		if 	((((m >> i) & 0x1)-((n >> i) & 0x1))!= 0) 
		{
			counts++;
		}
	}
	return counts;
}
int main()
{
	/*编程实现：
		两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
		输入例子 :
		1999 2299
		输出例子 : 7*/
	printf("%d\n",cmpBinary(1999,2299));
	system("pause");
	return 0;
}