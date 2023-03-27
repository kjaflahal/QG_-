#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//初始化栈
void initStack(LinkStack* Stack)
{
	Stack->count = 0;
	Stack->top = NULL;
}
//入栈
void pushStack(LinkStack*Stack)
{
    char temp[20];//放字符串
    printf("请输入：\n");
    scanf_s("%s", &temp);
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL)
    {
        printf("内存分配失败，无法入栈！\n");
        return;
    }
    strcpy(newNode->data, temp);
    newNode->next = Stack->top;
    Stack->top = newNode;
    Stack->count++;
    printf("入栈成功！\n");
}
//出栈
void popStack(LinkStack* Stack)
{
    if (Stack->count == 0)
    {
        printf("栈已空，出栈失败!\n");
        return;
    }
    StackNode* Temp = Stack->top;//保留栈顶指针的位置
    Stack->top = Temp->next;
    free(Temp);
    Stack->count--;
    printf("出栈成功！");

}
//判断栈是否为空
void isEmptyStack(LinkStack* Stack)
{
    if (Stack->count == 0)
    {
        printf("栈为空！\n");
        return;
    }
    printf("栈不为空！\n");
}
//检测栈的大小
int stackLength(LinkStack* Stack)
{
    return Stack->count;
}
//销毁栈
void destroyStack(LinkStack* Stack)
{
    while (Stack->top != NULL)
    {
        StackNode* Temp = Stack->top;//保留栈顶指针的位置
        Stack->top = Temp->next;
        free(Temp);
    }
    free(Stack->top);
    printf("栈已销毁！\n");
    return 0;
    
}
//清空栈
void clearStack(LinkStack* Stack)
{
    while (Stack->top != NULL)
    {
        StackNode* Temp = Stack->top;//保留栈顶指针的位置
        Stack->top = Temp->next;
        free(Temp);
    }
    printf("栈已清空！\n");
}
//判断栈是否存在
void isExistStack(LinkStack* Stack)
{
    if (Stack->top != NULL)
    {
        printf("栈不存在！");
    }
}
//得到栈顶元素
void getTopStack(LinkStack* Stack)
{
    if (Stack->count == 0)//空栈
    {
        printf("栈为空，无数据！\n");
    }
    printf("栈顶元素为：%s\n", &Stack->top->data);
}