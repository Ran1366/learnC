#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <malloc.h>

struct address_info
{
	char name[20];//����
	char sex[5];//�Ա�
	char age[5];//����
	char phone[20];//�绰
	char address[100];//��ַ
};
typedef struct address_info * pinfo;
int mumbers = 0;//��¼��ϵ�˵�������
int size = 1;//��¼ͨѶ¼�Ĺ�ģ��С
int sizeOfStruct = sizeof(struct address_info);//��¼�ṹ���С
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
//[��Ա����]ͨѶ¼����
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
//[��Ա����]�ֵ���Ƚ�������С
int namecmp(char name1[], char name2[])
{
	int result = -(strcmp(name1, name2));
	return result;
}
//[��Ա����]��ʾָ����ϵ��
void view_someone(pinfo *address_book, int num)
{
	printf("����		�Ա�	����	�绰		סַ\n");
	printf("%s		%s	%s	%s		%s\n",
		(*address_book)[num].name, (*address_book)[num].sex, (*address_book)[num].age,
		(*address_book)[num].phone, (*address_book)[num].address);
}
//[��Ա����]������ϵ���Ƿ����
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
//[��Ա����]д����ϵ����Ϣ
void input_info(pinfo *address_book, int num)
{
	printf("%p\n", address_book);
	printf("��������ϵ�˵�����\n");
	scanf("%s", (*address_book)[num].name);
	printf("��������ϵ���Ա�\n");
	scanf("%s", (*address_book)[num].sex);
	printf("��������ϵ������\n");
	scanf("%s", (*address_book)[num].age);
	printf("��������ϵ�˵绰\n");
	scanf("%s", (*address_book)[num].phone);
	printf("��������ϵ��סַ\n");
	scanf("%s", (*address_book)[num].address);
}
//[��Ա����]ɾ����ϵ����Ϣ
void delete_info(pinfo *address_book, char input_name[], int i)
{
	//������ҵ���,���Ҳ������һ����
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
		printf("����ϵ����ɾ��\n");
	}
	//����ҵ���,���������һ��
	if (i == mumbers - 1)
	{
		--mumbers;
		printf("����ϵ����ɾ��\n");
	}
}
//ͨѶ¼��ʼ��
void init(pinfo *address_book)
{
	if (*address_book != NULL)
	{
		mumbers = 0;
	}
}
//�����ϵ��
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
		printf("�ɹ������ϵ��\n");
	}
	else
	{
		printf("�����ϵ��ʧ��\n");
	}
}
//ɾ��ָ����ϵ��
void delete_contact(pinfo *address_book)
{
	printf("������Ҫɾ������ϵ��\n");
	char input_name[20];
	scanf("%s", &input_name);
	int result = find_is(address_book, input_name);
	if (result >= 0)
	{
		printf("���ҵ���ϵ��%s��ȷ��Ҫɾ����? y/n\n", input_name);
		char choise[2];
		scanf("%s", &choise);
		if (strcmp(choise, "y") == 0)
		{
			delete_info(address_book, input_name, result);
			//�����ǰ�洢����ϵ�˲���������1/10����С������ԭ����1/4
			if ((mumbers / size) * 10 < 1)
			{
				*address_book = (pinfo)realloc(*address_book, sizeOfStruct * size / 4);
				size /= 4;
			}
		}
		if (strcmp(choise, "n") == 0)
		{
			printf("ָ����ȡ��\n");
		}
	}
	else
	{
		printf("���޴���!\n");
	}
}
//����ָ����ϵ��
void find_contact(pinfo *address_book)
{
	printf("��������Ҫ���ҵ���ϵ��\n");
	char input_name[20];
	scanf("%s", &input_name);
	int i = find_is(address_book, input_name);
	if (i >= 0)
	{
		printf("����ϵ����Ϣ����:\n");
		view_someone(address_book, i);
	}
	else
	{
		printf("���޴���!\n");
	}
}
//�޸�ָ����ϵ����Ϣ
void modify_contact(pinfo *address_book)
{
	printf("��������Ҫ�޸ĵ���ϵ��\n");
	char input_name[20];
	scanf("%s", &input_name);
	int i = find_is(address_book, input_name);
	if (i >= 0)
	{
		printf("���ҵ���ϵ��%s��ȷ��Ҫ�޸���? y/n\n", input_name);
		char choise[2];
		scanf("%s", &choise);
		if (strcmp(choise, "y") == 0)
		{
			input_info(address_book, i);
			printf("�ɹ��޸���ϵ��!\n");
		}
		if (strcmp(choise, "n") == 0)
		{
			printf("ָ����ȡ��\n");
		}
	}
	else
	{
		printf("���޴���!\n");
	}
}
//��ʾ������ϵ��
void viewAll_contact(pinfo *address_book)
{
	printf("����%d����ϵ��,ȫ����ʾ����:\n", mumbers);
	printf("����		�Ա�	����	�绰		סַ\n");
	for (int i = 0; i < mumbers; ++i)
	{
		printf("%s		%s	%s	%s		%s\n",
			(*address_book)[i].name, (*address_book)[i].sex, (*address_book)[i].age,
			(*address_book)[i].phone, (*address_book)[i].address);
	}
}
//���������ϵ��
void emptyAll_contact(pinfo *address_book)
{
	printf("��ȷ��Ҫ���������ϵ����? y/n\n");
	char choise[2];
	scanf("%s", &choise);
	if (strcmp(choise, "y") == 0)
	{
		mumbers = 0;
		printf("�����������ϵ��!\n");
	}
	if (strcmp(choise, "n") == 0)
	{
		printf("ָ����ȡ��\n");
	}
}
//������������ϵ��
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
	printf("�������!\n");
}
//������ϵ�˵��ļ�
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
	printf("�ѱ�����ϵ��!\n");
}
//������ϵ��
void load_contact(pinfo *address_book)
{
	FILE *fp = fopen("./text.txt", "r");
	if (fp == NULL)
	{
		perror("fopen");
	}
	struct address_info buffer = { 0 };
	//��ȡ��ϵ��֮ǰ�Ƚ���һ�γ�ʼ��
	init(address_book);
	int i = 0;
	while (fread(&buffer, sizeOfStruct, 1, fp))
	{
		(*address_book)[i] = buffer;
		++i;
		++mumbers;
		//��ϵ�������������������
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
	printf("1.�����ϵ��\n");
	printf("2.ɾ����ϵ��\n");
	printf("3.�޸���ϵ��\n");
	printf("4.������ϵ��\n");
	printf("5.��ʾ������ϵ��\n");
	printf("6.���������ϵ��\n");
	printf("7.����������\n");
	printf("8.������ϵ�˵��ļ�\n");
	printf("9.������ϵ��\n");
	printf("0.�˳�\n");
	printf("����������ѡ��!\n");
	printf("============================\n");
	int choise = 0;
	scanf("%d", &choise);
	return choise;
}
int main()
{
	pinfo address_book = (pinfo)malloc(sizeOfStruct);
	printf("%p\n", address_book);
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
		save_contact,
		load_contact
	};
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
			printf("������������!\n");
			continue;
		}
		table[choise - 1](&address_book);
	}
	system("pause");
	return 0;
}