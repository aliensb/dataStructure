// ����ͼ�ٽӱ�ʵ��.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* ��󶥵�����Ӧ���û����� */
#define INFINITY 65535
typedef int status;
typedef char VertexType;
typedef int EdgeType;

typedef struct EgeNode {
	int adjIndex;
	EdgeType weight;
	EgeNode  * next = NULL;
}EgeNode;

typedef struct VertexNode {
	VertexType data;
	EgeNode * firstEge = NULL;

}VertexNode, adjList[MAXVEX];

typedef struct {
	adjList list;
	int vertexNu, egeNu;
}GraphAdj;


status creatGraph(GraphAdj *adj)
{
	char start, end;
	int v1 = 0, v2 = 0, w = INFINITY;
	printf("������ͼ�Ķ�����\n");
	cin >> adj->vertexNu;
	printf("������ͼ�ı���\n");
	cin >> adj->egeNu;
	for (int i = 0; i < adj->vertexNu; i++)
	{
		printf("�������%d������", i + 1);
		cin >> adj->list[i].data;
	}
	for (int i = 0; i < adj->egeNu; i++)
	{
		printf("�������%d���ߵ�����,��ʽ�磬AB5\n", i + 1);
		cin >> start;//�߿�ʼ�Ľڵ�
		cin >> end;//�߽����Ľڵ�
		cin >> w;//���ϵ�Ȩ��
		for (int j = 0; j < adj->vertexNu; j++)
		{
			if (adj->list[j].data == start)
				v1 = j;
			if (adj->list[j].data == end)
				v2 = j;
		}
		//ͷ�巨�����µı߽ڵ�
		EgeNode * node1 = (EgeNode*)malloc(sizeof(EgeNode));
		node1->next = adj->list[v1].firstEge;
		adj->list[v1].firstEge = node1;
		node1->weight = w;
		node1->adjIndex = v2;
	
	}
	return OK;
}
int main()
{
	GraphAdj adj;
	creatGraph(&adj);
	return 0;
}


