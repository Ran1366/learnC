#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ROW 10
#define COL 10
#define MINE 10
//记录有无胜负
int win = 1;
//记录还有没有没掀开的地区
int isopen = 1;
//创建两个数组，用来表示给玩家展示的界面和雷区的界面
char Show_Map[ROW + 2][COL + 2];
int Mine_Map[ROW + 2][COL + 2];
void BuildBoard()
{
	//时间种子
	srand((unsigned int)time(0));
	//把展示给玩家看的界面全都初始化为 '*'
	for (int row = 1 ; row < ROW + 1 ; row++)
	{
		for (int col = 1 ; col < COL + 1 ; col++)
		{
			Show_Map[row][col] = '*';
		}
	}
	//把雷区初始化为十个
	int count = 0;
	while (count < MINE)
	{
		int mine_x = rand() % 10 + 1;
		int mine_y = rand() % 10 + 1;
		if (Mine_Map[mine_x][mine_y] == 1)
		{
			continue;
		}
		else 
		{
			Mine_Map[mine_x][mine_y] = 1;
			count++;
		}
	}
}
void Print()
{
	printf("     ");
	for (int i = 1 ; i < ROW + 1 ; i++)
	{
		printf("%d ",i);
	}
	printf("\n     ____________________\n");
	for (int row = 1 ; row < ROW + 1 ; row++)
	{
		printf(" %02d |",row);
		for (int col = 1; col < COL + 1; col++)
		{
			printf("%c ", Show_Map[row][col]);
		}
		printf("\n");
	}
}
void PrintMine()
{
	printf("     ");
	for (int i = 1; i < ROW + 1; i++)
	{
		printf("%d ", i);
	}
	printf("\n     ____________________\n");
	for (int row = 1; row < ROW + 1; row++)
	{
		printf(" %02d |", row);
		for (int col = 1; col < COL + 1; col++)
		{
			printf("%d ", Mine_Map[row][col]);
		}
		printf("\n");
	}
}
//递归调用该函数，以打开更多的空白区域
void OpenMore(int x,int y,int num)
{
	num = Mine_Map[x - 1][y - 1] + Mine_Map[x - 1][y] + Mine_Map[x - 1][y + 1] + Mine_Map[x][y - 1] +
		Mine_Map[x][y + 1] + Mine_Map[x + 1][y - 1] + Mine_Map[x + 1][y] + Mine_Map[x + 1][y + 1];
	if (Show_Map[x][y] != '0' && x > 0 && x < ROW + 1 && y > 0 && y < COL + 1)
	{
		if (num == 0)
		{
			Show_Map[x][y] = '0';
			OpenMore(x - 1, y - 1, 0);
			OpenMore(x - 1, y, 0);
			OpenMore(x - 1, y + 1, 0);
			OpenMore(x, y - 1, 0);
			OpenMore(x, y + 1, 0);
			OpenMore(x + 1, y - 1, 0);
			OpenMore(x + 1, y, 0);
			OpenMore(x + 1, y + 1,0);

		}
		if (num > 0)
		{
			Show_Map[x][y] = num + '0';
		}
	}
}
//判断玩家输入后有什么结果
char Judge(int x,int y)
{
	//一,该地不是雷区
	if (Mine_Map[x][y] != 1 )
	{
		int mine_num = Mine_Map[x - 1][y - 1] + Mine_Map[x - 1][y] + Mine_Map[x - 1][y + 1] + Mine_Map[x][y - 1] +
					   Mine_Map[x][y + 1] + Mine_Map[x + 1][y - 1] + Mine_Map[x + 1][y] + Mine_Map[x + 1][y + 1];
		//该地周围有地雷
		if (mine_num > 0)
		{
			Show_Map[x][y] = mine_num + '0';
			return 'n';
		}
		//该地周围无地雷
		if (mine_num == 0)
		{
			OpenMore(x,y,0);
			return 'o';
		}
	}
	//2.该地区是雷区
	if (Mine_Map[x][y] == 1)
	{
		//表示游戏结束
		win = 0;
		return '0';
	}
	return 'n';
}
void PlayerMove()
{
	printf("请输入一个坐标,例如 “x y”\n");
	int player_x = -1;
	int player_y = -1;
	while(1)
	{ 
		scanf("%d %d", &player_x, &player_y);
		if (player_x < 1 || player_x > ROW + 1 || player_y < 1 || player_y > COL + 1)
		{
			printf("输入错误，请重新输入！\n");
			continue;
		}
		if (Show_Map[player_x][player_y] != '*')
		{
			printf("这个地方已经掀开了，请重新输入\n");
			continue;
		}
		//判断玩家输入后有什么结果
		char result = Judge(player_x, player_y);
		if (result == 'n' || result == 'o' || result == '0')
		{
			break;
		}
	}

}
//检测还有没有没被掀开的地方
void CheckMap()
{
	int count = 0;
	for (int row = 1; row < ROW + 1; row++)
	{
		for (int col = 1; col < COL + 1; col++)
		{
			if (Show_Map[row][col] == '*')
			{
				count++;
			}
		}
	}
	if (count == 10)
	{
		isopen = 0;
	}
}
int Menu()
{
	printf("===================扫雷游戏===================\n");
	printf("==================1.开始游戏===================\n");
	printf("==================2.退出游戏===================\n");
	int choise = 0;
	scanf("%d", &choise);
	if (choise == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void PlayGame()
{
	//生成一局新的游戏
	BuildBoard();
	//打印游戏界面，提示玩家开始扫雷
	//PrintMine();
	if (Menu() == 1)
	{
			Print();
			while (1)
			{
				//玩家输入坐标，并检查坐标是否合法
				PlayerMove();
				//若合法则判断是否是雷，不是雷就更新地图的显示，并揭开那块地区，否则游戏结束
				//直到十颗雷被完全找出，并且其他区域都被掀开则游戏胜利
				//检测还有没有没被掀开的地方，有则返回 1，否则返回 0
				Print();
				//检查还有没有没被掀开的空地
				CheckMap();
				if(win == 0 && isopen == 1)
				{
					//打印地雷图
					PrintMine();
					printf("扫雷失败！游戏结束！\n");
					break;
				}
				if (win == 1 && isopen == 0)
				{

					Print();
					PrintMine();
					printf("扫雷成功！游戏胜利！\n");
					break;
				}
			}
	}
}
int main()
{
	//扫雷游戏
	PlayGame();
	system("pause");
	return 0;
}