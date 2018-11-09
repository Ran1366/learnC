#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义学生这个结构体，有一个名字和3门课的分数
typedef struct 
{
	char name[20];
	int score[3];
}Student;
//登记学生信息
Student * SetStudent(Student * pStudent)
{
	printf("请输入学生的姓名——20个字符以内\n");
	scanf("%s", pStudent->name);
	for (int i = 0;i<3;)
	{
		printf("请输入学生的分数,1~5\n");
		int score = 0;
		scanf(" %d", &score);
		if (score > 0 && score < 6) 
		{
			pStudent->score[i] = score;
			i++;
		}
		else
		{
			printf("输入错误！");
		}
	}
	return pStudent;
}
//计算学生的平均成绩
double StudentAverage(const Student * pStudent)
{
	return (pStudent->score[0] + pStudent->score[1] + pStudent->score[2]) / 3.0;
}
//输出学生信息
void ShowStudent(const Student * pStudent)
{
	printf("%s\t%d\t%d\t%d\t%f\n",
			pStudent->name, pStudent->score[0],pStudent->score[1],pStudent->score[2], StudentAverage(pStudent));

}
//获得学生的一个成绩
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
	printf("NUM\t姓名\t科目一\t科目二\t科目三\t平均分\n");
	for (int i = 0;i<2;i++)
	{
		printf("%d\t",i+1);
		ShowStudent(&s[i]);
	}
	system("pause");
	return 0;
}