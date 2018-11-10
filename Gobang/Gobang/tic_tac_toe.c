#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//棋盘的行数
#define LINE 3
//棋盘的列数
#define COL 3
//有无胜负
int win = 0;
char G_Board[LINE][COL];
//生成棋盘
void BulidBoard()
{
	srand((unsigned int)time(0));
	for (int line = 0;line<LINE;line++)
	{
		for (int col = 0; col<COL;col++)
		{
			G_Board[line][col] = ' ';
		}
	}
}
//打印棋盘
void Print()
{
	int line = 0;
	for (int i = 0; i<COL; i++)
	{
		printf("____");
	}
	printf("_");
	for (;line <LINE; line++)
	{
		printf("\n|");
		for (int col = 0; col < COL ; col++)
		{
			printf(" %c |",G_Board[line][col]);
		}
		printf("\n|");
		for (int col = 0; col < COL; col++)
		{
			printf("___|");
		}

			//printf("| %c | %c | %c |\n",G_Board[line][0],G_Board[line][1],G_Board[line][2]);
			//printf("|___|___|___|\n");
	}
	printf("\n");
}
//玩家下棋
void PlayerTurn()
{
	printf("轮到玩家下棋：\n输入一个坐标：x y\n");
	int x = -1;
	int y = -1;
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x<1 || x>LINE || y<1 || y>COL)
		{
			printf("您输入的坐标错误，请重新输入！\n");
			continue;
		}
		if (G_Board[x-1][y-1] != ' ')
		{
			printf("该座标已有棋子，请重新输入！\n");
			continue;
		}
		G_Board[x-1][y-1] = 'x';
		Print();
		break;
	}
}
//电脑下棋
void ConputerTurn()
{
	while (1)
	{
		int x = rand() % LINE+1;
		int y = rand() % COL+1;
		if (x > 0 && x < LINE+1 && y>0 && y < COL+1 && G_Board[x-1][y-1] == ' ')
		{
			G_Board[x-1][y-1] = 'o';
			Print();
			break;
		}
	}
	
}
//检查横向有没有连成3个的相同棋子，返回x玩家赢，o电脑赢，n没有结果
char JudgeLine()
{
	for (int line = 0; line < LINE; line++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (G_Board[line][col] != ' '&& col < COL - 2 &&
				G_Board[line][col] == G_Board[line][col + 1] &&
				G_Board[line][col] == G_Board[line][col + 2])
			{
				if (G_Board[line][col] == 'x')
				{
					return 'x';
				}
				if (G_Board[line][col] == 'o')
				{
					return 'o';
				}
			}
		}
	}
	return 'n';
}
//检查纵向有没有连成3个的相同棋子，返回x玩家赢，o电脑赢，n没有结果
char JudeCol()
{
	for (int line = 0; line < LINE; line++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (G_Board[line][col] != ' '&& line < LINE - 2 &&
				G_Board[line][col] == G_Board[line+1][col] &&
				G_Board[line][col] == G_Board[line+2][col])
			{
				if (G_Board[line][col] == 'x')
				{
					return 'x';
				}
				if (G_Board[line][col] == 'o')
				{
					return 'o';
				}
			}
		}
	}
	return 'n';
}
//检查左斜有没有连成3个的相同棋子，返回x玩家赢，o电脑赢，n没有结果
char JudgeOblL()
{
	for (int line = 0; line < LINE; line++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (G_Board[line][col] != ' '&& line < LINE - 2 && col > 1 &&
				G_Board[line][col] == G_Board[line + 1][col - 1] &&
				G_Board[line][col] == G_Board[line + 2][col - 2])
			{
				if (G_Board[line][col] == 'x')
				{
					return 'x';
				}
				if (G_Board[line][col] == 'o')
				{
					return 'o';
				}
			}
		}
	}
	return 'n';
}
//检查右斜有没有连成3个的相同棋子，返回x玩家赢，o电脑赢，n没有结果
char JudgeOblR()
{
	for (int line = 0; line < LINE; line++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (G_Board[line][col] != ' '&& line < LINE - 2 && col < COL-2 &&
				G_Board[line][col] == G_Board[line + 1][col + 1] &&
				G_Board[line][col] == G_Board[line + 2][col + 2])
			{
				if (G_Board[line][col] == 'x')
				{
					return 'x';
				}
				if (G_Board[line][col] == 'o')
				{
					return 'o';
				}
			}
		}
	}
	return 'n';
}
//判断棋盘有没有下满,没满返回1，满了返回2
int IsFull()
{
	for (int line = 0; line < LINE; line++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (G_Board[line][col] == ' ')
			{
				return 1;
			}
		}
	}
	return 2;
}
//判断胜负，返回x玩家赢，o电脑赢，p平局
char WhoIsWinner()
{
	//判断胜负
	if (IsFull())
	{
		if (JudgeLine() == 'x' || JudeCol() == 'x' || JudgeOblL() == 'x' || JudgeOblR() == 'x')
		{
			win = 1;
			return 'x';
		}
		if (JudgeLine() == 'o' || JudeCol() == 'o' || JudgeOblL() == 'o' || JudgeOblR() == 'o')
		{
			win = 1;
			return 'o';
		}
	}
	//棋盘下满，并且没有胜负则平局
	if (IsFull() == 2 && win == 0)
	{
		return 'p';
	}
	return 'n';
}

int main()
{
	//实现一个三子棋游戏，需要玩家和电脑下棋
	//1.初始化一个棋盘
	BulidBoard();
	//2.打印棋盘
	Print();
	//3.玩家下棋，打印棋盘，判断胜负
	//4.电脑下棋，打印棋盘，判断胜负
	//如果胜负未分，棋盘仍未下满，重复2，3步骤，直至和局或一方胜利
	while (1)
	{
		PlayerTurn();
		if (WhoIsWinner() == 'x')
		{
			printf("玩家胜！\n");
			break;
		}
		if (WhoIsWinner() == 'o')
		{
			printf("电脑胜！\n");
			break;
		}
		if (WhoIsWinner() == 'p')
		{
			printf("平局!\n");
			break;
		}
		ConputerTurn();
		if (WhoIsWinner() == 'x')
		{
			printf("玩家胜！\n");
			break;
		}
		if (WhoIsWinner() == 'o')
		{
			printf("电脑胜！\n");
			break;
		}
		if(WhoIsWinner() == 'p')
		{
			printf("平局!\n");
			break;
		}
	}
	system("pause");
	return 0;
}