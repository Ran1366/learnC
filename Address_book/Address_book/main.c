#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct address_info
{
	char name[20];//����
	char sex[5];//�Ա�
	char age[5];//����
	char phone[20];//�绰
	char address[100];//��ַ
};
struct address_info address_book[1000];//��̬ͨѶ¼,��ϵ������Ϊ1000��
int mumbers = 0;//��¼��ϵ�˵�������
//[��Ա����]�ֵ���Ƚ�������С
int namecmp(char name1[],char name2[])
{
	int result = -(strcmp(name1, name2));
	return result;
}
//[��Ա����]��ʾָ����ϵ��
void view_someone(int num)
{
	printf("����		�Ա�	����	�绰		סַ\n");
	printf("%s		%s	%s	%s		%s\n",
		address_book[num].name, address_book[num].sex, address_book[num].age,
		address_book[num].phone, address_book[num].address);
}
//[��Ա����]������ϵ���Ƿ����
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
//[��Ա����]д����ϵ����Ϣ
void input_info(int num)
{
	printf("��������ϵ�˵�����\n");
	scanf("%s",&address_book[num].name);
	printf("��������ϵ���Ա�\n");
	scanf("%s", &address_book[num].sex);
	printf("��������ϵ������\n");
	scanf("%s", &address_book[num].age);
	printf("��������ϵ�˵绰\n");
	scanf("%s", &address_book[num].phone);
	printf("��������ϵ��סַ\n");
	scanf("%s", &address_book[num].address);
}
//[��Ա����]ɾ����ϵ����Ϣ
void delete_info(char input_name[],int i)
{
	//������ҵ���,���Ҳ������һ����
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
void init()
{
	if (&address_book != NULL)
	{
		mumbers = 0;
	}
}
//�����ϵ��
void add_contact()
{
	input_info(mumbers);
	++mumbers;
	printf("�ɹ������ϵ��\n");
}
//ɾ��ָ����ϵ��
void delete_contact()
{
	printf("������Ҫɾ������ϵ��\n");
	char input_name[20];
	scanf("%s", &input_name);
	int result = find_is(input_name);
	if (result >= 0)
	{
		printf("���ҵ���ϵ��%s��ȷ��Ҫɾ����? y/n\n",input_name);
		char choise[2];
		scanf("%s", &choise);
		if (strcmp(choise,"y") == 0)
		{
			delete_info(input_name, result);
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
void find_contact()
{
	printf("��������Ҫ���ҵ���ϵ��\n");
	char input_name[20];
	scanf("%s", &input_name);
	int i = find_is(input_name);
	if (i >= 0)
	{
		printf("����ϵ����Ϣ����:\n");
		view_someone(i);
	}
	else
	{
		printf("���޴���!\n");
	}
}
//�޸�ָ����ϵ����Ϣ
void modify_contact()
{
	printf("��������Ҫ�޸ĵ���ϵ��\n");
	char input_name[20];
	scanf("%s",&input_name);
	int i = find_is(input_name);
	if (i >= 0)
	{
		printf("���ҵ���ϵ��%s��ȷ��Ҫ�޸���? y/n\n", input_name);
		char choise[2];
		scanf("%s", &choise);
		if (strcmp(choise, "y") == 0)
		{
			input_info(i);
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
void viewAll_contact()
{
	printf("����%d����ϵ��,ȫ����ʾ����:\n",mumbers);
	printf("����		�Ա�	����	�绰		סַ\n");
	for (int i = 0; i < mumbers; ++i)
	{
		
		printf("%s		%s	%s	%s		%s\n",
			address_book[i].name, address_book[i].sex, address_book[i].age,
			address_book[i].phone, address_book[i].address);
	}
}
//���������ϵ��
void emptyAll_contact()
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
	printf("�������!\n");
}
//������ϵ�˵��ļ�
void save_contact()
{
	FILE *fp = fopen("./text.txt","w");
	if (fp == NULL)
	{
		perror("fopen");
	}
	//fputs("����		�Ա�	����	�绰		סַ\n", fp);
	for (int i =  0; i < mumbers; ++i)
	{
		fwrite(&address_book[i],sizeof(address_book[0]),1,fp);
	}
	fclose(fp);
	printf("�ѱ�����ϵ��!\n");
}
//������ϵ��
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
			printf("������������!\n");
			continue;
		}
		table[choise - 1]();
	}
	system("pause");
	return 0;
}