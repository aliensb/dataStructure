// ѭ������.cpp : Defines the entry point for the console application.
//



/*
��������:(rear+1)%queSize==front
���г��ȣ�rear-front+queSize)%queSize
�����п�rear==front
*/
#include "stdafx.h"
#include<stdlib.h>

typedef int ElemType;
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int status;
typedef struct {
	ElemType data[MAXSIZE];
	int front;
	int rear;
} Queue;
status initQueue(Queue * que)
{
	que->front = 0;
	que->rear = 0;
	return OK;
}
bool isQueueFull(Queue *que)
{
	if ((que->rear + 1) % MAXSIZE == que->front)
		return TRUE;
	return FALSE;
	
}

bool isQueEmpty(Queue * que)
{
	if (que->front == que->rear)
		return TRUE;
	return FALSE;

}
int getQueLength(Queue * que)
{
	return (que->rear - que->front + MAXSIZE) % MAXSIZE;
}

status enQueue(Queue * que,ElemType e)
{
	if (!isQueueFull(que))
	{
		que->data[que->rear] = e;
		que->rear = (que->rear + 1) % MAXSIZE;
		return OK;
	}
	return FALSE;
} 

status deQueue(Queue * que, ElemType * e)
{
	if (!isQueEmpty(que))
	{
		*e = que->data[que->front];
		que->front= (que->front + 1) % MAXSIZE;
		return OK;
	}
	return FALSE;
}
int main()
{
	Queue que;
	initQueue(&que);
	for (int i = 0; i < 10; i++)
	{
		printf("����� %d\n", i);
		enQueue(&que, i);
	}
	ElemType e;
	while (!isQueEmpty(&que))
	{
		if (deQueue(&que, &e))
			printf("������ %d \n", e);
		else
			printf("���󣬶�����Ϊ��");
	}
	system("pause");
    return 0;
}

