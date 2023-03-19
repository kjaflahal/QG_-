#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
//�˵�:
int menu()
{
	while (1)
	{
		printf("1.��ʾ����\n");
		printf("2.��ż�ڵ�Ե�\n");
		printf("3.Ѱ���м�ڵ��ֵ\n");
		printf("4.�ж��Ƿ���ѭ������\n");
		printf("5.�ǵݹ鷴ת����\n");
		printf("6.�ݹ鷴ת����\n");
		printf("7.��������\n");
		printf("8.�����½ڵ�\n");
		printf("0,�˳�\n");
		printf("\n");
		printf("������ 0 ~ 8 ������:");
		int choice = 1;
		scanf_s("%d", &choice);
		printf("\n\n");
		if (0 <= choice && choice <= 8)
		{
			return choice;
		}
		else
		{
			printf("�����������������룡\n");
		}
	}
}
//���ڴ���������ADT:
typedef struct linkList {
	int num;
	struct linkList* next;
}List;
//���ڴ���˫����ADT:
typedef struct duLinkList {
	int num;
	struct duLinkList* pre;
	struct duLinkList* next;
}duList;
//����������:
List* InitlistList_singe(List*Head)
{
	List* h1, * h2;
	Head= (List*)malloc(sizeof(List));
	h1 = h2 = Head;
	scanf_s("%d", &h1->num);
	while (h1->num!=1111)
	{
		h1 = (List*)malloc(sizeof(List));
		h2->next = h1;
		h1->next = NULL;
		h2 = h1;
		scanf_s("%d", &h1->num);
	}
	return Head;
}
//����˫����:
duList* InitlistList_double()
{
	duList* Head, * h1, * h2;
	Head = (duList*)malloc(sizeof(duList));
	h1 = h2 = Head;
	Head->pre = NULL;
	h1 = (duList*)malloc(sizeof(duList));
	scanf_s("%d", &h1->num);
	while (h1->num!=11111111111111111111)
	{
		h1 = (duList*)malloc(sizeof(duList));
		h2->next = h1;
		h1->pre = h2;
		h1->next = NULL;
		h2 = h1;
		scanf_s("%d", &h1->num);
	}
	return Head;
}
//��������ż����:
 List* ExchangeList(List* p)
{
	if (p == NULL || p->next == NULL)//ȷ���ڵ����2
		return p;
	List* u1 = p, * u2 = p->next, * u3 = p;
	p = u2;
	u1->next = u2->next;
	u2->next = u1;
	u2 = u1->next;
	if (u2 != NULL)
	{
		u1 = u2;
		u2 = u2->next;
	}
	while (u1 != NULL && u2 != NULL)
	{
		u3->next = u2;
		u1->next = u2->next;
		u2->next = u1;
		u2 = u1->next;
		u3 = u1;
		if (u2 != NULL)
		{
			u1 = u2;
			u2 = u2->next;
		}

	}
	return p;
}
//�������:
void printList(List*Head)
{
	if (Head == NULL)
	{
		printf("\nEEROR\n");
		return;
	}
	List* h1;
	h1 = Head;
	while(h1!=NULL)
	{
		printf("%d\n", h1->num);
		h1 = h1->next;
	}
}
//�ҵ���������е�:
List* FindmidPoint(List* Head)
{
	//����ָ�뷨
	if (Head == NULL)
		return 0;
	if (Head->next == NULL)
		return 0;
	List* fast, * slow;
	fast = slow = Head;
	while (1)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast==NULL||fast->next == NULL)//�����ڵ�
		{
			//printf("�м�ڵ����ݣ� %d\n", slow->num);
			return slow;
		}
		if (fast == NULL)//ż���ڵ�
		{
			//printf("�м�ڵ����ݣ� %d\n", slow->num);
			return slow;
		}
	}
}
//�ж������Ƿ�ɻ�:
void* judgeCircle(List* Head)
{
	//����ָ�뷨
	List* fast, * slow;
	fast = slow = Head;
	while (fast != NULL && fast->next != NULL)
	{
		
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			printf("Yes\n\n");
			return 0;
		}
	}
	printf("No\n\n");
	return 0;
}
//��ת�����ݹ�ͷǵݹ飩:
List* InvertedList(List* Head)
{
	return 0;
}
//�����������:
void destroyList(List* Head)
{
	List* temp = Head;
	while (temp != NULL)
	{
		List* node = temp;//tempָ���ƶ�ǰ��λ��
		temp = temp->next;//temp��ǰ��
		free(node);//�ͷ�
	}
	printf("���ٳɹ�");
	return ;
}
//������Ĳ���:
void insertList(List* end)
{
	printf("\n������Ҫ�洢�����֣�");
	if (end == NULL)
		return;
	List* h1, * h2;
	h1 = (List*)malloc(sizeof(List));
	end->next = h1;
	scanf_s("%d", &h1->num);
	h1->next = NULL;
	printf("\n����ɹ�\n");
}
int main()
{
	List* Head = NULL, *end;
	printf("����Ҫ�洢�������Դ�������\n(�� 1111 Ϊ���)\n");
	end=Head=InitlistList_singe(Head);
	system("cls");
	int choice = 1;
	int back=1;
	while (choice)
	{
		choice = menu();
		switch (choice)
		{
		case 0:
			return 0;
		case 1:
			printList(Head);//�������
			break;
		case 2:
			Head=ExchangeList(Head);//����
			printList(Head);
			break;
		case 3:
			printf("%d\n", FindmidPoint(Head)->num);//Ѱ���м�ֵ
			break;
		case 4:
			judgeCircle(Head);//�жϻ�
			break;
		case 5:
			//QAQ
			break;
		case 6:
			//QAQ
			break;
		case 7:
			destroyList(Head);//���������
			Head = NULL;//�սڵ���Խ���printList������
			break;
		case 8:
			if (end != NULL)
			{
				while (end->next != NULL)
					end = end->next;
				insertList(end);
				break; 
			}
		}
		printf("\n�����κ����ַ��ز˵�:\n");
		scanf_s("%d", &back);
		system("cls");

	}
	return 0;
}
