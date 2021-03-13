#include<iostream>
#include<string>
//#include"Digraph.h"
#include"DirectedCycle.h"
using namespace std;



DirectedCycle::DirectedCycle( class Digraph G)
{
	//Digraph newG(G);
	m_marked = new bool[G.V()];
	m_hasCycle = false;
	m_onStack = new bool[G.V()];
	for (int i = 0; i < G.V(); i++)
	{
		m_marked[i] = false;
		m_onStack[i] = false;
	}

	for (int v = 0; v < G.V(); v++)
	{
		if (m_marked[v] == false)
		{
			this->dfs(G, v);
		}
	}
}

bool DirectedCycle::hasCycle() const
{
	return this->m_hasCycle;
	
}

void DirectedCycle::dfs(class Digraph G, int v) const
{
	m_marked[v] = true;
	m_onStack[v] = true;
	Queue<int> adjtmp = G.adj[v];
	//Queue<int> q_tmp = G.adj[v];
	while (!adjtmp.isEmpty())
	{
		int w = adjtmp.dequeue();
		if (m_marked[w] == false)
		{
			dfs(G, w);
		}
		

		if (m_onStack[w])
		{
			m_hasCycle = true;
			return;
		}
		//cout << G.adj[v].dequeue() << endl;
	}
	m_onStack[v] = false;
}



DirectedCycle::~DirectedCycle()
{
	delete m_marked;
	delete m_onStack;
	m_marked = NULL;
	m_onStack = NULL;
	cout << "DirectedCycle析构函数调用" << endl;
}