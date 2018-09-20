// 无向图邻接矩阵表示.cpp : Defines the entry point for the console application.
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
#define MAXVEX 100 /* 最大顶点数，应由用户定义 */
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
	printf("请输入顶点的数量\n");
	scanf("%d", &(g->vertexNum));
	printf("请输入边的数量\n");
	scanf("%d", &(g->edgesNum));
	char start, end;
	int x=0,y=0,w= INFINITY;
	for (int i = 0; i < g->vertexNum; i++)
	{
		printf("请输入第%d个定点的值\n",i);
		cin >> g->vertexs[i];
	}
	//初始化整个邻接表
	for (int i = 0; i < g->edgesNum; i++)
	{
		for (int j = 0; j < g->edgesNum; j++)
		{
			g->edges[i][j] = INFINITY;
		}
	}
	for (int i = 0; i < g->edgesNum; i++)
	{
		printf("请输入第%d条边的数据,格式如，AB5\n", i + 1);
		cin >> start;//边开始的节点
		cin >> end;//边结束的节点
		cin >> w;//边上的权重
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
