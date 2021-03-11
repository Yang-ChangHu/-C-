#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include"Graph.h"
#include"DepthFirstSearch.h"
using namespace std;



DepthFirstSearch::DepthFirstSearch(Graph G, int s)
{
	this->marked = new bool[G.V()];
	for (int i = 0; i < G.V();i++)
	{
		marked[i] = false;
	}
	this->counts = 0;
	dfs(G, s);
}


void DepthFirstSearch::dfs(Graph G, int v)
{
	marked[v] = true;
	int w;
	while (!( G.Adj(v).empty()))
	{
		w = G.Adj(v).front();
		if (!marked[w])
		{
			dfs(G, w);
		}
		(G.adj[v]).pop();
	}
	counts++;

}

bool DepthFirstSearch::Marked(int w) const
{
	return marked[w];
}

int  DepthFirstSearch::Count() const
{
	return counts;
}