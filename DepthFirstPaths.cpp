#include<iostream>
#include<string>
#include"stack.hpp"
#include"Graph.h"
#include<queue>
#include"DepthFirstPaths.h"
using namespace std;

DepthFirstPaths::DepthFirstPaths(Graph G, int s)
{
	this->marked = new bool[G.V()];
	for (int i = 0; i < G.V(); i++)
	{
		marked[i] = false;
	}
	this->s = s;
	this->edgeTo = new int[G.V()];
	for (int i = 0; i < G.V(); i++)
	{
		edgeTo[i] = -1;
	}
	dfs(G, s);
}
bool DepthFirstPaths::hasPathTo(int v)
{
	return marked[v];
}
stack<int> DepthFirstPaths::pathRo(int v)
{

	stack<int> sk1;
	for (; edgeTo[v] != -1; v = edgeTo[v])
	{
		sk1.push(v);
	}
	return sk1;
}
void DepthFirstPaths::dfs(Graph G, int v)
{
	marked[v] = true;
	while (!G.adj[v].empty())
	{
		int w = G.adj[v].front();
		G.adj[v].pop();
		if (!marked[w])
		{
			edgeTo[w] = v;
			dfs(G, w);
		}
	}

}

DepthFirstPaths::~DepthFirstPaths()
{
	delete this->marked;
	this->marked = NULL;
	delete this->edgeTo;
	this->edgeTo = NULL;
}