#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义链栈节点结构体
typedef struct StackNode
{
	struct StackNode* next;
	float data;
}Node;
// 定义链栈结构体
typedef struct LinkStack
{
	int count;//栈中元素个数
	Node* top;//栈顶指针
} Stack;
//函数声名
void initStack(Stack* stack);
void pushStack(Stack* stack, float N);
float popStack(Stack* stack);
int isemptyStack(Stack* stack);
float getTopStack(Stack* stack);

void cal();
int priority(char sign);//优先级判断
int isNumber(float N);//数字判断
int isSign(float N);//运算符判断

//int stackLength(Stack* stack);
//void clearStack(Stack* stack);
//void isExistStack(Stack* stack);
//void pushStack(Stack* stack);