#include"Graph.h"
#include<iostream>
#include<string>
#include<queue>
#include"BreadthFirstSearch.h"
using namespace std;

BreadthFirstSearch::BreadthFirstSearch(Graph G, int s)
{
	this->marked = new bool[G.V()];
	for (int i = 0; i < G.V();i++)
	{
		this->marked[i] = false;
	}
	this->count = 0;
	bfs(G, s);
	
}
bool BreadthFirstSearch::Marked(int w)
{
	return marked[w];
}
int BreadthFirstSearch::Count()
{
	return count;
}

void BreadthFirstSearch::bfs(Graph G, int s)
{
	marked[s] = true;
	this->waitSearch.push(s);
	while (!this->waitSearch.empty())
	{
		int wait=this->waitSearch.front();
		while (!G.adj[wait].empty())
		{
			this->waitSearch.push(G.adj[wait].front());
			G.adj[wait].pop();
		}
		if (!marked[wait])
		{
			marked[wait] = true;
			count++;

		}
		
		this->waitSearch.pop();
		
	}
	

}

