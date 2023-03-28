#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  "Head.h"
//优先级
int priority(char sign)
{
    switch (sign)
    {
    case '(':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
//判断是否为数字
int isNumber(float N)
{
    if (N >= 0 && N <= 9)
    {
        return 1;
    }
}
//判断是否为运算符
int isSign(float N)
{
    if (N == 43 || N == 45 || N == 47 || N == 42)
    {
        return 1;
    }
}
void cal()
{
	Stack NumStack, SignStack;
	initStack(&NumStack);//数字栈
	initStack(&SignStack);//字符栈
	char arr[50] = { 0 };
	printf("输入要计算的式子：\n");
    scanf("%s", arr);
    int h = 0;
  
    float num1, num2;//用于计算栈顶两数
    int i = 0;
    float val = 0;
    while (arr[i] != '\0' || isemptyStack(&SignStack) != 1)
    {
        if (arr[i] >= '0' && arr[i] <= '9')
        {
            val = val * 10 + arr[i] - '0';
            i++;
            if (arr[i] < '0' || arr[i]>'9' )//如果下一个是字符，将上一个数字入栈
            {
                pushStack(&NumStack,val);//入栈
                val = 0;
            }
        }
        else
        {
            if (isemptyStack(&SignStack) == 1 || priority(arr[i])> priority(getTopStack(&SignStack))|| (getTopStack(&SignStack)=='(' && arr[i] != ')'))
            {//栈为空；优先级更高时入栈
                pushStack(&SignStack,arr[i]);
                i++;
                continue;
            }
            if (getTopStack(&SignStack) == '(' && arr[i] == ')')
            {
                popStack(&SignStack);//左括号后可入栈
                i++;
                continue;
            }
            if (priority(arr[i]) <= priority(getTopStack(&SignStack)) || arr[i] == ')' && getTopStack(&SignStack) != '(' || arr[i] == '\0' && isemptyStack(&SignStack) != 1)
            {
                char sign = popStack(&SignStack);
                switch(sign)
                {
                case '+':
                    num1 = popStack(&NumStack);
                    num2 = popStack(&NumStack);
                    pushStack(&NumStack, num2 + num1);
                    break;
                case '-':
                    num1 = popStack(&NumStack);
                    num2 = popStack(&NumStack);
                    pushStack(&NumStack, num2 - num1);
                    break;
                case '*':
                    num1 = popStack(&NumStack);
                    num2 = popStack(&NumStack);
                    pushStack(&NumStack, num2 * num1);
                    break;
                case '/':
                    num1 = popStack(&NumStack);
                    num2 = popStack(&NumStack);
                    pushStack(&NumStack, num2 / num1);
                    break;
                default:
                    break;
                }
            }
        }
    }
    printf("%f\n", getTopStack(&NumStack));

}
