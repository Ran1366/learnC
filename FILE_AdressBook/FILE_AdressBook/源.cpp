#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <malloc.h>

struct address_info
{
	char name[20];//姓名
	char sex[5];//性别
	char age[5];//年龄
	char phone[20];//电话
	char address[100];//地址
};
typedef struct address_info * pinfo;
int mumbers = 0;//记录联系人的总人数
int size = 1;//记录通讯录的规模大小
int sizeOfStruct = sizeof(struct address_info);//记录结构体大小
int namecmp(char name1[], char name2[]);
void view_someone(pinfo *address_book, int num);
int find_is(pinfo *address_book, char input_name[]);
void input_info(pinfo *address_book, int num);
void delete_info(pinfo *address_book, char input_name[], int i);
void init(pinfo *address_book);
void add_contact(pinfo *address_book);
void delete_contact(pinfo *address_book);
void find_contact(pinfo *address_book);
void modify_contact(pinfo *address_book);
void viewAll_contact(pinfo *address_book);
void emptyAll_contact(pinfo *address_book);
void sortAll_contact(pinfo *address_book);
void save_contact(pinfo *address_book);
void load_contact(pinfo *address_book);
int expandCapacity(pinfo *address_book);
//[成员函数]通讯录扩容
int expandCapacity(pinfo *paddress_book)
{
	*paddress_book = (pinfo)realloc(*paddress_book, sizeOfStruct * (mumbers * 2));
	if (*paddress_book != NULL)
	{
		size = 2 * mumbers;
		printf("expand capacity sucessful!\n");
		return 1;
	}
	else
	{
		printf("failed!\n");
		return 0;
	}
}
//[成员函数]字典序比较姓名大小
int namecmp(char name1[], char name2[])
{
	int result = -(strcmp(name1, name2));
	return result;
}
//[成员函数]显示指定联系人
void view_someone(pinfo *address_book, int num)
{
	printf("姓名		性别	年龄	电话		住址\n");
	printf("%s		%s	%s	%s		%s\n",
		(*address_book)[num].name, (*address_book)[num].sex, (*address_book)[num].age,
		(*address_book)[num].phone, (*address_book)[num].address);
}
//[成员函数]查找联系人是否存在
int find_is(pinfo *address_book, char input_name[])
{
	int i = 0;
	for (; i < mumbers; ++i)
	{
		if (strcmp((*address_book)[i].name, input_name) == 0)
		{
			return i;
		}
	}
	return -1;
}
//[成员函数]写入联系人信息
void input_info(pinfo *address_book, int num)
{
	//printf("%p\n", address_book);
	printf("请输入联系人的姓名\n");
	scanf("%s", (*address_book)[num].name);
	printf("请输入联系人性别\n");
	scanf("%s", (*address_book)[num].sex);
	printf("请输入联系人年龄\n");
	scanf("%s", (*address_book)[num].age);
	printf("请输入联系人电话\n");
	scanf("%s", (*address_book)[num].phone);
	printf("请输入联系人住址\n");
	scanf("%s", (*address_book)[num].address);
}
//[成员函数]删除联系人信息
void delete_info(pinfo *address_book, char input_name[], int i)
{
	//如果查找到了,并且不是最后一个人
	if (i != mumbers - 1)
	{
		for (; i < mumbers; ++i)
		{
			strcpy((*address_book)[i].name, (*address_book)[i + 1].name);
			strcpy((*address_book)[i].sex, (*address_book)[i + 1].sex);
			strcpy((*address_book)[i].age, (*address_book)[i + 1].age);
			strcpy((*address_book)[i].phone, (*address_book)[i + 1].phone);
			strcpy((*address_book)[i].address, (*address_book)[i + 1].address);
		}
		--mumbers;
		printf("该联系人已删除\n");
	}
	//如果找到了,并且是最后一人
	if (i == mumbers - 1)
	{
		--mumbers;
		printf("该联系人已删除\n");
	}
}
//通讯录初始化
void init(pinfo *address_book)
{
	if (*address_book != NULL)
	{
		mumbers = 0;
	}
}
//添加联系人
void add_contact(pinfo *address_book)
{
	int result = 1;
	if (mumbers >= size)
	{
		result = expandCapacity(address_book);
	}
	if (result == 1)
	{
		input_info(address_book, mumbers);
		++mumbers;
		save_contact(address_book);
		printf("成功添加联系人\n");
	}
	else
	{
		printf("添加联系人失败\n");
	}
}
//删除指定联系人
void delete_contact(pinfo *address_book)
{
	printf("请输入要删除的联系人\n");
	char input_name[20];
	scanf("%s", &input_name);
	int result = find_is(address_book, input_name);
	if (result >= 0)
	{
		printf("查找到联系人%s您确定要删除吗? y/n\n", input_name);
		char choise[2];
		scanf("%s", &choise);
		if (strcmp(choise, "y") == 0)
		{
			delete_info(address_book, input_name, result);
			save_contact(address_book);
			//如果当前存储的联系人不到容量的1/10就缩小容量到原来的1/4
			if ((mumbers / size) * 10 < 1)
			{
				*address_book = (pinfo)realloc(*address_book, sizeOfStruct * size / 4);
				size /= 4;
			}
		}
		if (strcmp(choise, "n") == 0)
		{
			printf("指令已取消\n");
		}
	}
	else
	{
		printf("查无此人!\n");
	}
}
//查找指定联系人
void find_contact(pinfo *address_book)
{
	printf("请输入你要查找的联系人\n");
	char input_name[20];
	scanf("%s", &input_name);
	int i = find_is(address_book, input_name);
	if (i >= 0)
	{
		printf("该联系人信息如下:\n");
		view_someone(address_book, i);
	}
	else
	{
		printf("查无此人!\n");
	}
}
//修改指定联系人信息
void modify_contact(pinfo *address_book)
{
	printf("请输入你要修改的联系人\n");
	char input_name[20];
	scanf("%s", &input_name);
	int i = find_is(address_book, input_name);
	if (i >= 0)
	{
		printf("查找到联系人%s您确定要修改吗? y/n\n", input_name);
		char choise[2];
		scanf("%s", &choise);
		if (strcmp(choise, "y") == 0)
		{
			input_info(address_book, i);
			save_contact(address_book);
			printf("成功修改联系人!\n");
		}
		if (strcmp(choise, "n") == 0)
		{
			printf("指令已取消\n");
		}
	}
	else
	{
		printf("查无此人!\n");
	}
}
//显示所有联系人
void viewAll_contact(pinfo *address_book)
{
	init(address_book);
	load_contact(address_book);
	printf("共有%d个联系人,全部显示如下:\n", mumbers);
	printf("姓名		性别	年龄	电话		住址\n");
	for (int i = 0; i < mumbers; ++i)
	{
		printf("%s		%s	%s	%s		%s\n",
			(*address_book)[i].name, (*address_book)[i].sex, (*address_book)[i].age,
			(*address_book)[i].phone, (*address_book)[i].address);
	}
}
//清空所有联系人
void emptyAll_contact(pinfo *address_book)
{
	printf("您确定要清空所有联系人吗? y/n\n");
	char choise[2];
	scanf("%s", &choise);
	if (strcmp(choise, "y") == 0)
	{
		mumbers = 0;
		save_contact(address_book);
		printf("已清空所有联系人!\n");
	}
	if (strcmp(choise, "n") == 0)
	{
		printf("指令已取消\n");
	}
}
//按名字排序联系人
void sortAll_contact(pinfo *address_book)
{
	for (int i = 0; i < mumbers - 1; ++i)
	{
		for (int j = 0; j < mumbers - i - 1; ++j)
		{
			if (namecmp((*address_book)[i].name, (*address_book)[i + 1].name) < 0)
			{
				struct address_info temp;
				temp = (*address_book)[i];
				(*address_book)[i] = (*address_book)[i + 1];
				(*address_book)[i + 1] = temp;
			}
		}
	}
	save_contact(address_book);
	printf("排序完成!\n");
}
//保存联系人到文件
void save_contact(pinfo *address_book)
{
	FILE *fp = fopen("./text.txt", "w");
	if (fp == NULL)
	{
		perror("fopen");
	}
	for (int i = 0; i < mumbers; ++i)
	{
		fwrite(&(*address_book)[i], sizeof((*address_book)[0]), 1, fp);
	}
	fclose(fp);
	//printf("已保存联系人!\n");
}
//加载联系人
void load_contact(pinfo *address_book)
{
	FILE *fp = fopen("./text.txt", "r");
	if (fp == NULL)
	{
		perror("fopen");
	}
	struct address_info buffer = { 0 };
	//读取联系人之前先进行一次初始化
	init(address_book);
	int i = 0;
	while (fread(&buffer, sizeOfStruct, 1, fp))
	{
		(*address_book)[i] = buffer;
		++i;
		++mumbers;
		//联系人数量即将溢出则扩容
		if (mumbers >= size)
		{
			expandCapacity(address_book);
		}
	}
	fclose(fp);
}
int menu()
{
	printf("============================\n");
	printf("1.添加联系人\n");
	printf("2.删除联系人\n");
	printf("3.修改联系人\n");
	printf("4.查找联系人\n");
	printf("5.显示所有联系人\n");
	printf("6.清空所有联系人\n");
	printf("7.按名字排序\n");
	//printf("8.保存联系人到文件\n");
	//printf("9.加载联系人\n");
	printf("0.退出\n");
	printf("请输入您的选择!\n");
	printf("============================\n");
	int choise = 0;
	scanf("%d", &choise);
	return choise;
}
int main()
{
	pinfo address_book = (pinfo)malloc(sizeOfStruct);
	//printf("%p\n", address_book);
	init(&address_book);
	typedef void(*pfuction)(pinfo*);
	pfuction table[] = {
		add_contact,
		delete_contact,
		modify_contact,
		find_contact,
		viewAll_contact,
		emptyAll_contact,
		sortAll_contact,
		//save_contact,
		//load_contact
	};
	load_contact(&address_book);
	while (1)
	{
		int choise = menu();
		if (choise == 0)
		{
			printf("Good Bye!\n");
			free(address_book);
			break;
		}
		if (choise < 0 || choise >(int)(sizeof(table) / sizeof(table[0])))
		{
			printf("您的输入有误!\n");
			continue;
		}
		table[choise - 1](&address_book);
	}
	system("pause");
	return 0;
}