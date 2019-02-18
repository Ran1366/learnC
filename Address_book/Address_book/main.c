#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct address_info
{
	char name[20];//姓名
	char sex[5];//性别
	char age[5];//年龄
	char phone[20];//电话
	char address[100];//地址
};
struct address_info address_book[1000];//静态通讯录,联系人上限为1000个
int mumbers = 0;//记录联系人的总人数
//[成员函数]字典序比较姓名大小
int namecmp(char name1[],char name2[])
{
	int result = -(strcmp(name1, name2));
	return result;
}
//[成员函数]显示指定联系人
void view_someone(int num)
{
	printf("姓名		性别	年龄	电话		住址\n");
	printf("%s		%s	%s	%s		%s\n",
		address_book[num].name, address_book[num].sex, address_book[num].age,
		address_book[num].phone, address_book[num].address);
}
//[成员函数]查找联系人是否存在
int find_is(char input_name[])
{
	int i = 0;
	for (; i < mumbers; ++i)
	{
		if (strcmp(address_book[i].name, input_name) == 0)
		{
			return i;
		}
	}
	return -1;
}
//[成员函数]写入联系人信息
void input_info(int num)
{
	printf("请输入联系人的姓名\n");
	scanf("%s",&address_book[num].name);
	printf("请输入联系人性别\n");
	scanf("%s", &address_book[num].sex);
	printf("请输入联系人年龄\n");
	scanf("%s", &address_book[num].age);
	printf("请输入联系人电话\n");
	scanf("%s", &address_book[num].phone);
	printf("请输入联系人住址\n");
	scanf("%s", &address_book[num].address);
}
//[成员函数]删除联系人信息
void delete_info(char input_name[],int i)
{
	//如果查找到了,并且不是最后一个人
	if (i != mumbers - 1)
	{
		for (; i < mumbers; ++i)
		{
			strcpy(address_book[i].name, address_book[i + 1].name);
			strcpy(address_book[i].sex, address_book[i + 1].sex);
			strcpy(address_book[i].age, address_book[i + 1].age);
			strcpy(address_book[i].phone, address_book[i + 1].phone);
			strcpy(address_book[i].address, address_book[i + 1].address);
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
void init()
{
	if (&address_book != NULL)
	{
		mumbers = 0;
	}
}
//添加联系人
void add_contact()
{
	input_info(mumbers);
	++mumbers;
	printf("成功添加联系人\n");
}
//删除指定联系人
void delete_contact()
{
	printf("请输入要删除的联系人\n");
	char input_name[20];
	scanf("%s", &input_name);
	int result = find_is(input_name);
	if (result >= 0)
	{
		printf("查找到联系人%s您确定要删除吗? y/n\n",input_name);
		char choise[2];
		scanf("%s", &choise);
		if (strcmp(choise,"y") == 0)
		{
			delete_info(input_name, result);
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
void find_contact()
{
	printf("请输入你要查找的联系人\n");
	char input_name[20];
	scanf("%s", &input_name);
	int i = find_is(input_name);
	if (i >= 0)
	{
		printf("该联系人信息如下:\n");
		view_someone(i);
	}
	else
	{
		printf("查无此人!\n");
	}
}
//修改指定联系人信息
void modify_contact()
{
	printf("请输入你要修改的联系人\n");
	char input_name[20];
	scanf("%s",&input_name);
	int i = find_is(input_name);
	if (i >= 0)
	{
		printf("查找到联系人%s您确定要修改吗? y/n\n", input_name);
		char choise[2];
		scanf("%s", &choise);
		if (strcmp(choise, "y") == 0)
		{
			input_info(i);
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
void viewAll_contact()
{
	printf("共有%d个联系人,全部显示如下:\n",mumbers);
	printf("姓名		性别	年龄	电话		住址\n");
	for (int i = 0; i < mumbers; ++i)
	{
		
		printf("%s		%s	%s	%s		%s\n",
			address_book[i].name, address_book[i].sex, address_book[i].age,
			address_book[i].phone, address_book[i].address);
	}
}
//清空所有联系人
void emptyAll_contact()
{
	printf("您确定要清空所有联系人吗? y/n\n");
	char choise[2];
	scanf("%s", &choise);
	if (strcmp(choise, "y") == 0)
	{
		mumbers = 0;
		printf("已清空所有联系人!\n");
	}
	if (strcmp(choise, "n") == 0)
	{
		printf("指令已取消\n");
	}
}
//按名字排序联系人
void sortAll_contact()
{
	for (int i = 0 ; i < mumbers - 1 ; ++i)
	{
		for (int j = 0 ; j < mumbers - i - 1; ++j)
		{
			if (namecmp(address_book[i].name,address_book[i + 1].name) < 0)
			{
				struct address_info temp;
				temp = address_book[i];
				address_book[i] = address_book[i + 1];
				address_book[i + 1] = temp;
			}
		}
	}
	printf("排序完成!\n");
}
//保存联系人到文件
void save_contact()
{
	FILE *fp = fopen("./text.txt","w");
	if (fp == NULL)
	{
		perror("fopen");
	}
	//fputs("姓名		性别	年龄	电话		住址\n", fp);
	for (int i =  0; i < mumbers; ++i)
	{
		fwrite(&address_book[i],sizeof(address_book[0]),1,fp);
	}
	fclose(fp);
	printf("已保存联系人!\n");
}
//加载联系人
void load_contact()
{
	FILE *fp = fopen("./text.txt", "r");
	if (fp == NULL)
	{
		perror("fopen");
	}
	struct address_info buffer = {0};
	int i = 0;
	while (fread(&buffer, sizeof(address_book[0]), 1, fp))
	{
		address_book[i] = buffer;
		++i;
		++mumbers;
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
	printf("8.保存联系人到文件\n");
	printf("9.加载联系人\n");
	printf("0.退出\n");
	printf("请输入您的选择!\n");
	printf("============================\n");
	int choise = 0;
	scanf("%d",&choise);
	return choise;
}
int main()
{
	init();
	typedef void(*pfuction)();
	pfuction table[] = {
		add_contact,
		delete_contact,
		modify_contact,
		find_contact,
		viewAll_contact,
		emptyAll_contact,
		sortAll_contact,
		save_contact,
		load_contact
	};
	while (1)
	{
		int choise = menu();
		if (choise == 0)
		{
			printf("Good Bye!\n");
			break;
		}
		if (choise < 0 || choise > (int)(sizeof(table)/sizeof(table[0])))
		{
			printf("您的输入有误!\n");
			continue;
		}
		table[choise - 1]();
	}
	system("pause");
	return 0;
}