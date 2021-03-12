#include<iostream>
#include<string>
#include"stack.hpp"
#include"DepthFirstOrder.h"
using namespace std;

DepthOrder::DepthOrder(class Digraph G)
{
	this->marked = new bool[G.V()];
	for (int i = 0; i < G.V(); i++)
	{
		marked[i] = false;
	}

	for (int i = 0; i < G.V(); i++)
	{
		if (!marked[i])
		{
			dfs(G, i);
		}
		
	}
}
stack<int> DepthOrder::ReversePost()
{
	return reversePost;
}

void DepthOrder::dfs(class Digraph G, int v)
{
	marked[v] = true;
	
	while (!G.adj[v].isEmpty())
	{
		int w = G.adj[v].head->element;
		if (!marked[w])
		{
			dfs(G, w);
			//
		}
		//else
		//{
			cout <<"������"<< G.adj[v].dequeue() << endl;
		//}
		
		
	}
	reversePost.push(v);

}

DepthOrder::~DepthOrder()
{
	delete this->marked;
	this->marked = NULL;
	cout << "~DepthOrder������������" << endl;
}