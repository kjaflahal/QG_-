#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  "Head.h"
//���ȼ�
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
//�ж��Ƿ�Ϊ����
int isNumber(float N)
{
    if (N >= 0 && N <= 9)
    {
        return 1;
    }
}
//�ж��Ƿ�Ϊ�����
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
	initStack(&NumStack);//����ջ
	initStack(&SignStack);//�ַ�ջ
	char arr[50] = { 0 };
	printf("����Ҫ�����ʽ�ӣ�\n");
    scanf("%s", arr);
    int h = 0;
  
    float num1, num2;//���ڼ���ջ������
    int i = 0;
    float val = 0;
    while (arr[i] != '\0' || isemptyStack(&SignStack) != 1)
    {
        if (arr[i] >= '0' && arr[i] <= '9')
        {
            val = val * 10 + arr[i] - '0';
            i++;
            if (arr[i] < '0' || arr[i]>'9' )//�����һ�����ַ�������һ��������ջ
            {
                pushStack(&NumStack,val);//��ջ
                val = 0;
            }
        }
        else
        {
            if (isemptyStack(&SignStack) == 1 || priority(arr[i])> priority(getTopStack(&SignStack))|| (getTopStack(&SignStack)=='(' && arr[i] != ')'))
            {//ջΪ�գ����ȼ�����ʱ��ջ
                pushStack(&SignStack,arr[i]);
                i++;
                continue;
            }
            if (getTopStack(&SignStack) == '(' && arr[i] == ')')
            {
                popStack(&SignStack);//�����ź����ջ
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
