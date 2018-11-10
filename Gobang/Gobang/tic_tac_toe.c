#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//���̵�����
#define LINE 3
//���̵�����
#define COL 3
//����ʤ��
int win = 0;
char G_Board[LINE][COL];
//��������
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
//��ӡ����
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
//�������
void PlayerTurn()
{
	printf("�ֵ�������壺\n����һ�����꣺x y\n");
	int x = -1;
	int y = -1;
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x<1 || x>LINE || y<1 || y>COL)
		{
			printf("�����������������������룡\n");
			continue;
		}
		if (G_Board[x-1][y-1] != ' ')
		{
			printf("�������������ӣ����������룡\n");
			continue;
		}
		G_Board[x-1][y-1] = 'x';
		Print();
		break;
	}
}
//��������
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
//��������û������3������ͬ���ӣ�����x���Ӯ��o����Ӯ��nû�н��
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
//���������û������3������ͬ���ӣ�����x���Ӯ��o����Ӯ��nû�н��
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
//�����б��û������3������ͬ���ӣ�����x���Ӯ��o����Ӯ��nû�н��
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
//�����б��û������3������ͬ���ӣ�����x���Ӯ��o����Ӯ��nû�н��
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
//�ж�������û������,û������1�����˷���2
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
//�ж�ʤ��������x���Ӯ��o����Ӯ��pƽ��
char WhoIsWinner()
{
	//�ж�ʤ��
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
	//��������������û��ʤ����ƽ��
	if (IsFull() == 2 && win == 0)
	{
		return 'p';
	}
	return 'n';
}

int main()
{
	//ʵ��һ����������Ϸ����Ҫ��Һ͵�������
	//1.��ʼ��һ������
	BulidBoard();
	//2.��ӡ����
	Print();
	//3.������壬��ӡ���̣��ж�ʤ��
	//4.�������壬��ӡ���̣��ж�ʤ��
	//���ʤ��δ�֣�������δ�������ظ�2��3���裬ֱ���;ֻ�һ��ʤ��
	while (1)
	{
		PlayerTurn();
		if (WhoIsWinner() == 'x')
		{
			printf("���ʤ��\n");
			break;
		}
		if (WhoIsWinner() == 'o')
		{
			printf("����ʤ��\n");
			break;
		}
		if (WhoIsWinner() == 'p')
		{
			printf("ƽ��!\n");
			break;
		}
		ConputerTurn();
		if (WhoIsWinner() == 'x')
		{
			printf("���ʤ��\n");
			break;
		}
		if (WhoIsWinner() == 'o')
		{
			printf("����ʤ��\n");
			break;
		}
		if(WhoIsWinner() == 'p')
		{
			printf("ƽ��!\n");
			break;
		}
	}
	system("pause");
	return 0;
}