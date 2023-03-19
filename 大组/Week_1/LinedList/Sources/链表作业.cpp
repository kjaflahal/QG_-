#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
//菜单:
int menu()
{
	while (1)
	{
		printf("1.显示链表\n");
		printf("2.奇偶节点对调\n");
		printf("3.寻找中间节点的值\n");
		printf("4.判断是否是循环链表\n");
		printf("5.非递归反转链表\n");
		printf("6.递归反转链表\n");
		printf("7.销毁链表\n");
		printf("8.插入新节点\n");
		printf("0,退出\n");
		printf("\n");
		printf("请输入 0 ~ 8 的数字:");
		int choice = 1;
		scanf_s("%d", &choice);
		printf("\n\n");
		if (0 <= choice && choice <= 8)
		{
			return choice;
		}
		else
		{
			printf("输入有误，请重新输入！\n");
		}
	}
}
//用于创建单链表ADT:
typedef struct linkList {
	int num;
	struct linkList* next;
}List;
//用于创建双链表ADT:
typedef struct duLinkList {
	int num;
	struct duLinkList* pre;
	struct duLinkList* next;
}duList;
//创建单链表:
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
//创建双链表:
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
//单链表奇偶调换:
 List* ExchangeList(List* p)
{
	if (p == NULL || p->next == NULL)//确保节点大于2
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
//输出链表:
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
//找到单链表的中点:
List* FindmidPoint(List* Head)
{
	//快慢指针法
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
		if (fast==NULL||fast->next == NULL)//奇数节点
		{
			//printf("中间节点数据： %d\n", slow->num);
			return slow;
		}
		if (fast == NULL)//偶数节点
		{
			//printf("中间节点数据： %d\n", slow->num);
			return slow;
		}
	}
}
//判断链表是否成环:
void* judgeCircle(List* Head)
{
	//快慢指针法
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
//反转链表（递归和非递归）:
List* InvertedList(List* Head)
{
	return 0;
}
//单链表的销毁:
void destroyList(List* Head)
{
	List* temp = Head;
	while (temp != NULL)
	{
		List* node = temp;//temp指针移动前的位置
		temp = temp->next;//temp向前移
		free(node);//释放
	}
	printf("销毁成功");
	return ;
}
//单链表的插入:
void insertList(List* end)
{
	printf("\n请输入要存储的数字：");
	if (end == NULL)
		return;
	List* h1, * h2;
	h1 = (List*)malloc(sizeof(List));
	end->next = h1;
	scanf_s("%d", &h1->num);
	h1->next = NULL;
	printf("\n插入成功\n");
}
int main()
{
	List* Head = NULL, *end;
	printf("输入要存储的数字以创建链表：\n(以 1111 为最后)\n");
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
			printList(Head);//输出链表
			break;
		case 2:
			Head=ExchangeList(Head);//交换
			printList(Head);
			break;
		case 3:
			printf("%d\n", FindmidPoint(Head)->num);//寻找中间值
			break;
		case 4:
			judgeCircle(Head);//判断环
			break;
		case 5:
			//QAQ
			break;
		case 6:
			//QAQ
			break;
		case 7:
			destroyList(Head);//链表的销毁
			Head = NULL;//空节点可以进入printList函数中
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
		printf("\n输入任何数字返回菜单:\n");
		scanf_s("%d", &back);
		system("cls");

	}
	return 0;
}
