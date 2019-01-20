#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int drinkWater(int money)
{
	assert(money > 0);
	int wnum = 0;//喝的饮料数量
	int bnum = 0;//空瓶子数量
	int i = 0;
	for (i = 1; i <= money; ++i)
	{
		++wnum;
		++bnum;
		if (bnum == 2)//每两个空瓶换一瓶饮料
		{
			++wnum;
			bnum = 1;
		}
	}
	return wnum;
}
int main()
{
	//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水， 
	//给20元，可以多少汽水。 
	int money = 20;
	int num = drinkWater(money);
	printf("%d元,可以喝%d瓶饮料\n", money, num);

	system("pause");
	return 0;
}