#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������ջ�ڵ�ṹ��
typedef struct StackNode
{
	struct StackNode* next;
	float data;
}Node;
// ������ջ�ṹ��
typedef struct LinkStack
{
	int count;//ջ��Ԫ�ظ���
	Node* top;//ջ��ָ��
} Stack;
//��������
void initStack(Stack* stack);
void pushStack(Stack* stack, float N);
float popStack(Stack* stack);
int isemptyStack(Stack* stack);
float getTopStack(Stack* stack);

void cal();
int priority(char sign);//���ȼ��ж�
int isNumber(float N);//�����ж�
int isSign(float N);//������ж�

//int stackLength(Stack* stack);
//void clearStack(Stack* stack);
//void isExistStack(Stack* stack);
//void pushStack(Stack* stack);