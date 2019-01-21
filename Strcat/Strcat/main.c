#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
char * Strcat(char * des, const char * sor)
{
	assert(des != NULL);
	assert(sor != NULL);
	int locat = 0;//记录目标空间的结尾的下标
	while (des[locat] != '\0')
	{
		++locat;
	}
	des[locat] = sor[0];
	int i = 1;
	while (sor[i] != '\0')
	{
		des[locat + i] = sor[i];
		++i;
	}
	des[locat + i] = '\0';
	return des;
}
int main()
{
	//自己写的strcat
	char des[1024] = "";
	Strcat(des,"hello ");
	printf("%s\n", des);
	Strcat(des,"world ");
	printf("%s\n", des);
	Strcat(des,"hehe.");
	printf("%s\n", des);
	system("pause");
	return 0;
}