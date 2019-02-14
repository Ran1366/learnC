#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char a[5];
	//b是一个数组指针,该指针指向一个含有5个元素的数组
	char(*b)[5] = &a;
	printf("%p\n", b);
	printf("%p\n", &a);



	//这是一个指针数组
	//数组里的每一个元素都是字符串,可以用指针数组来保存
	//char *b[5] = { "aaa","bbb","ccc","ddd","eee" };
	
















	//int a = 10;
	//int *pa = &a;//取a的地址并赋给指针pa
	//int **ppa = &pa;//取一级指针pa的地址并赋给二级指针ppa
	////下面这三条语句都打印a的地址
	//printf("%p\n", &a);//打印a的地址
	//printf("%p\n", pa);//打印pa的内容
	//printf("%p\n\n", *ppa);//打印ppa解引用后的内容
	////下面这两条语句都打印pa的地址
	//printf("%p\n", &pa);//打印pa的地址
	//printf("%p\n\n",ppa);//打印ppa的内容
	////下面这三条语句都打印10
	//printf("%d\n", a);
	//printf("%d\n",*pa);//*解引用得到a,此时*pa就是a
	////ppa两次解引用得到a,第一次解引用得到pa的内容,也即是a的地址
	////第二次解引用得到a的内容,也就是10
	//printf("%d\n", *(*ppa));
	system("pause");
	return 0;
}