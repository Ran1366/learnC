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
	/*���ʵ�֣�
		����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
		�������� :
		1999 2299
		������� : 7*/
	printf("%d\n",cmpBinary(1999,2299));
	system("pause");
	return 0;
}