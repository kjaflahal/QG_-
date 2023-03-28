#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Head.h"
//初始化栈
void initStack(Stack* stack)
{
    stack->count = 0;
    stack->top = NULL;
}
//入栈
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
//出栈
float popStack(Stack* stack)
{
    float t;
    if (stack->count == 0)
    {
        return;
    }
    Node* Temp = stack->top;//保留栈顶指针的位置
    stack->top = Temp->next;
    t = Temp->data;
    free(Temp);
    stack->count--;
    return t;
}
//判断栈是否为空
int isemptyStack(Stack* stack)
{
    if (stack->count == 0)
    {
        return 1;
    }
    return 0;
}
//获取栈顶元素
float getTopStack(Stack* stack)
{
    if (stack->count == 0)//空栈
    {
        return;
    }
    return stack->top->data;
}