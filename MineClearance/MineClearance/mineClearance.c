#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ROW 10
#define COL 10
#define MINE 10
//��¼����ʤ��
int win = 1;
//��¼����û��û�ƿ��ĵ���
int isopen = 1;
//�����������飬������ʾ�����չʾ�Ľ���������Ľ���
char Show_Map[ROW + 2][COL + 2];
int Mine_Map[ROW + 2][COL + 2];
void BuildBoard()
{
	//ʱ������
	srand((unsigned int)time(0));
	//��չʾ����ҿ��Ľ���ȫ����ʼ��Ϊ '*'
	for (int row = 1 ; row < ROW + 1 ; row++)
	{
		for (int col = 1 ; col < COL + 1 ; col++)
		{
			Show_Map[row][col] = '*';
		}
	}
	//��������ʼ��Ϊʮ��
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
//�ݹ���øú������Դ򿪸���Ŀհ�����
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
//�ж�����������ʲô���
char Judge(int x,int y)
{
	//һ,�õز�������
	if (Mine_Map[x][y] != 1 )
	{
		int mine_num = Mine_Map[x - 1][y - 1] + Mine_Map[x - 1][y] + Mine_Map[x - 1][y + 1] + Mine_Map[x][y - 1] +
					   Mine_Map[x][y + 1] + Mine_Map[x + 1][y - 1] + Mine_Map[x + 1][y] + Mine_Map[x + 1][y + 1];
		//�õ���Χ�е���
		if (mine_num > 0)
		{
			Show_Map[x][y] = mine_num + '0';
			return 'n';
		}
		//�õ���Χ�޵���
		if (mine_num == 0)
		{
			OpenMore(x,y,0);
			return 'o';
		}
	}
	//2.�õ���������
	if (Mine_Map[x][y] == 1)
	{
		//��ʾ��Ϸ����
		win = 0;
		return '0';
	}
	return 'n';
}
void PlayerMove()
{
	printf("������һ������,���� ��x y��\n");
	int player_x = -1;
	int player_y = -1;
	while(1)
	{ 
		scanf("%d %d", &player_x, &player_y);
		if (player_x < 1 || player_x > ROW + 1 || player_y < 1 || player_y > COL + 1)
		{
			printf("����������������룡\n");
			continue;
		}
		if (Show_Map[player_x][player_y] != '*')
		{
			printf("����ط��Ѿ��ƿ��ˣ�����������\n");
			continue;
		}
		//�ж�����������ʲô���
		char result = Judge(player_x, player_y);
		if (result == 'n' || result == 'o' || result == '0')
		{
			break;
		}
	}

}
//��⻹��û��û���ƿ��ĵط�
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
	printf("===================ɨ����Ϸ===================\n");
	printf("==================1.��ʼ��Ϸ===================\n");
	printf("==================2.�˳���Ϸ===================\n");
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
	//����һ���µ���Ϸ
	BuildBoard();
	//��ӡ��Ϸ���棬��ʾ��ҿ�ʼɨ��
	//PrintMine();
	if (Menu() == 1)
	{
			Print();
			while (1)
			{
				//����������꣬����������Ƿ�Ϸ�
				PlayerMove();
				//���Ϸ����ж��Ƿ����ף������׾͸��µ�ͼ����ʾ�����ҿ��ǿ������������Ϸ����
				//ֱ��ʮ���ױ���ȫ�ҳ��������������򶼱��ƿ�����Ϸʤ��
				//��⻹��û��û���ƿ��ĵط������򷵻� 1�����򷵻� 0
				Print();
				//��黹��û��û���ƿ��Ŀյ�
				CheckMap();
				if(win == 0 && isopen == 1)
				{
					//��ӡ����ͼ
					PrintMine();
					printf("ɨ��ʧ�ܣ���Ϸ������\n");
					break;
				}
				if (win == 1 && isopen == 0)
				{

					Print();
					PrintMine();
					printf("ɨ�׳ɹ�����Ϸʤ����\n");
					break;
				}
			}
	}
}
int main()
{
	//ɨ����Ϸ
	PlayGame();
	system("pause");
	return 0;
}