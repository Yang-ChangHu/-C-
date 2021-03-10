#pragma once
#include<iostream>
#include<string>
#include<queue>
#include"Graph.h"
using namespace std;

class DepthFirstSearch
{
public:

	//构造深度图搜索对象，使用深度优先搜索找出s顶点中所有想通的顶点
	DepthFirstSearch(Graph G, int s);

	//判断w顶点是否与s顶点想通
	bool Marked(int w) const;

	//获取与s顶点想通的所有顶点个数
	int Count() const;
private:

	//使用深度优先搜索找出G图中v顶点的所有相通顶点
	void dfs(Graph G, int v);

	//索引代表顶点，表示当前顶点是否已经被搜索
	bool* marked;	
	
	//记录有多少个顶点与s相通
	int counts;
};