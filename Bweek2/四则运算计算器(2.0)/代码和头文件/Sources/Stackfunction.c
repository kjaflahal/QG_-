#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Head.h"
//��ʼ��ջ
void initStack(Stack* stack)
{
    stack->count = 0;
    stack->top = NULL;
}
//��ջ
void pushStack(Stack* stack, float N)
{
    Node* newNode =(Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return;
    }
    newNode->data = N;
    newNode->next =stack->top;
    stack->top=newNode ;
    stack->count++;
}
//��ջ
float popStack(Stack* stack)
{
    float t;
    if (stack->count == 0)
    {
        return;
    }
    Node* Temp = stack->top;//����ջ��ָ���λ��
    stack->top = Temp->next;
    t = Temp->data;
    free(Temp);
    stack->count--;
    return t;
}
//�ж�ջ�Ƿ�Ϊ��
int isemptyStack(Stack* stack)
{
    if (stack->count == 0)
    {
        return 1;
    }
    return 0;
}
//��ȡջ��Ԫ��
float getTopStack(Stack* stack)
{
    if (stack->count == 0)//��ջ
    {
        return;
    }
    return stack->top->data;
}