#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//����ѧ������ṹ�壬��һ�����ֺ�3�ſεķ���
typedef struct 
{
	char name[20];
	int score[3];
}Student;
//�Ǽ�ѧ����Ϣ
Student * SetStudent(Student * pStudent)
{
	printf("������ѧ������������20���ַ�����\n");
	scanf("%s", pStudent->name);
	for (int i = 0;i<3;)
	{
		printf("������ѧ���ķ���,1~5\n");
		int score = 0;
		scanf(" %d", &score);
		if (score > 0 && score < 6) 
		{
			pStudent->score[i] = score;
			i++;
		}
		else
		{
			printf("�������");
		}
	}
	return pStudent;
}
//����ѧ����ƽ���ɼ�
double StudentAverage(const Student * pStudent)
{
	return (pStudent->score[0] + pStudent->score[1] + pStudent->score[2]) / 3.0;
}
//���ѧ����Ϣ
void ShowStudent(const Student * pStudent)
{
	printf("%s\t%d\t%d\t%d\t%f\n",
			pStudent->name, pStudent->score[0],pStudent->score[1],pStudent->score[2], StudentAverage(pStudent));

}
//���ѧ����һ���ɼ�
int GetScore(const Student * pStudent,int index)
{
	return pStudent->score[index];
}
int main()
{
	Student s[2];
	for (int i = 0;i < 2; i++)
	{
		Student *p = &s[i];
		SetStudent(p);
	}
	printf("NUM\t����\t��Ŀһ\t��Ŀ��\t��Ŀ��\tƽ����\n");
	for (int i = 0;i<2;i++)
	{
		printf("%d\t",i+1);
		ShowStudent(&s[i]);
	}
	system("pause");
	return 0;
}