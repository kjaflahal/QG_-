#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//��ʼ��ջ
void initStack(LinkStack* Stack)
{
	Stack->count = 0;
	Stack->top = NULL;
}
//��ջ
void pushStack(LinkStack*Stack)
{
    char temp[20];//���ַ���
    printf("�����룺\n");
    scanf_s("%s", &temp);
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL)
    {
        printf("�ڴ����ʧ�ܣ��޷���ջ��\n");
        return;
    }
    strcpy(newNode->data, temp);
    newNode->next = Stack->top;
    Stack->top = newNode;
    Stack->count++;
    printf("��ջ�ɹ���\n");
}
//��ջ
void popStack(LinkStack* Stack)
{
    if (Stack->count == 0)
    {
        printf("ջ�ѿգ���ջʧ��!\n");
        return;
    }
    StackNode* Temp = Stack->top;//����ջ��ָ���λ��
    Stack->top = Temp->next;
    free(Temp);
    Stack->count--;
    printf("��ջ�ɹ���");

}
//�ж�ջ�Ƿ�Ϊ��
void isEmptyStack(LinkStack* Stack)
{
    if (Stack->count == 0)
    {
        printf("ջΪ�գ�\n");
        return;
    }
    printf("ջ��Ϊ�գ�\n");
}
//���ջ�Ĵ�С
int stackLength(LinkStack* Stack)
{
    return Stack->count;
}
//����ջ
void destroyStack(LinkStack* Stack)
{
    while (Stack->top != NULL)
    {
        StackNode* Temp = Stack->top;//����ջ��ָ���λ��
        Stack->top = Temp->next;
        free(Temp);
    }
    free(Stack->top);
    printf("ջ�����٣�\n");
    return 0;
    
}
//���ջ
void clearStack(LinkStack* Stack)
{
    while (Stack->top != NULL)
    {
        StackNode* Temp = Stack->top;//����ջ��ָ���λ��
        Stack->top = Temp->next;
        free(Temp);
    }
    printf("ջ����գ�\n");
}
//�ж�ջ�Ƿ����
void isExistStack(LinkStack* Stack)
{
    if (Stack->top != NULL)
    {
        printf("ջ�����ڣ�");
    }
}
//�õ�ջ��Ԫ��
void getTopStack(LinkStack* Stack)
{
    if (Stack->count == 0)//��ջ
    {
        printf("ջΪ�գ������ݣ�\n");
    }
    printf("ջ��Ԫ��Ϊ��%s\n", &Stack->top->data);
}