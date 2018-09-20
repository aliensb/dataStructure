// ����ͼ�ڽӾ����ʾ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
# include<iostream>
using namespace std;
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* ��󶥵�����Ӧ���û����� */
#define INFINITY 65535
typedef int status;
typedef char VertexType;
typedef int EdgeType;
typedef struct {
	VertexType vertexs[MAXVEX];
	EdgeType edges[MAXVEX][MAXVEX];
	int vertexNum, edgesNum;
} Graph;

status createGraph(Graph * g)
{
	printf("�����붥�������\n");
	scanf("%d", &(g->vertexNum));
	printf("������ߵ�����\n");
	scanf("%d", &(g->edgesNum));
	char start, end;
	int x=0,y=0,w= INFINITY;
	for (int i = 0; i < g->vertexNum; i++)
	{
		printf("�������%d�������ֵ\n",i);
		cin >> g->vertexs[i];
	}
	//��ʼ�������ڽӱ�
	for (int i = 0; i < g->edgesNum; i++)
	{
		for (int j = 0; j < g->edgesNum; j++)
		{
			g->edges[i][j] = INFINITY;
		}
	}
	for (int i = 0; i < g->edgesNum; i++)
	{
		printf("�������%d���ߵ�����,��ʽ�磬AB5\n", i + 1);
		cin >> start;//�߿�ʼ�Ľڵ�
		cin >> end;//�߽����Ľڵ�
		cin >> w;//���ϵ�Ȩ��
		for (int j = 0; j < g->vertexNum; j++)
		{
			if (g->vertexs[j] == start)
				x = j;
			if (g->vertexs[j] == end)
				y = j;
		}
		g->edges[x][y] = w;
		g->edges[y][x] = w;
	}
	return OK;
}

int main(void)
{
	Graph g;
	createGraph(&g);
	return 0;
}
