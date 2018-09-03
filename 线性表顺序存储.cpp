// ���Ա�.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MAXSIZE 20
typedef int ElemType;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int status;

typedef struct
{
	ElemType data[MAXSIZE];
	int length;
} SqlList;
status initList(SqlList * l)
{
	l->length = 0;
	return OK;
}
status getElem(SqlList * l, int i, ElemType * e)
{
	//�����ĳ���С��0������Ҫȡ��Ԫ�ر��С��1������Ҫȥ��Ԫ�ر�Ŵ��ڱ�ĳ���
	//����Ԫ�صı�Ŵ�1��ʼ��ţ������ڱ��Ϊ0��Ԫ��
	if (l->length == 0 || i<1 || i>l->length+1)
		return ERROR;
	*e = l->data[i - 1];//i��Ԫ�صı�ţ���Ԫ�ص��±��Ǵ�0��ʼ��ŵģ�Ԫ���������е��±����Ԫ�صı�ż�һ
	return OK;
}
status insertList(SqlList *l, int i, ElemType e)
{
	if (l->length == MAXSIZE)//������
		return ERROR;
	if(i<1||i>l->length+1)//�����λ���ڵ�һ��ǰ���������������һ��Ԫ�غ�+1��λ�ӣ��������ɹ���������м����
		return ERROR;
	if (i < l->length) //�����λ���ڱ������м䣬��Ҫ������λ�ú�������������ƶ�
	{
		for (int k = l->length - 1; k >= i - 1; k--)
		{
			l->data[k + 1] = l->data[k];
		 }
	}
	l->data[i - 1] = e;
	l->length++;
	return OK;
}

status listDel(SqlList *l, int i)
{
	if (l->length == 0)//��Ϊ�յ�ʱ����ɾ��
		return ERROR;
	if (i<1 || i>l->length)//ɾ����Ԫ�ر�Ų���С��1������ɾ�����ڱ��Ⱥ������
		return ERROR;
	for (; i < l->length - 1; i++)
	{
		l->data[i - 1] = l->data[i];
	}
	l->length--;
	return OK;
}
void printList(SqlList* l)
{
	for (int i = 0; i < l->length - 1; i++)
	{
		printf("%d", l->data[i]);
		if (i != l->length - 2)
			printf(",");
	}

	printf("\n");
}
//char 1B,short 2B,int 4B,long 4B,float 4B,
int main()
{
	SqlList list;
	ElemType e;
	status st;
	int j, k;
	st=initList(&list);
	printf("��ʼ����list�ĳ���Ϊ��%d \n", list.length);
	for (int j = 0; j <= 5; j++)
	{
		insertList(&list, 1, j);//�������е�һ��Ԫ�ز���
		printf("�������� %d \n", j);
	}
	printList(&list);
	listDel(&list, 3);
	printList(&list);
	getchar();
    return 0;
}

