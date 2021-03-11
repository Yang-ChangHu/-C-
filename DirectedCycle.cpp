#include<iostream>
#include<string>
#include"Digraph.h"
#include"DirectedCycle.h"
using namespace std;



DirectedCycle::DirectedCycle(Digraph G)
{
	//m_marked = new bool[G.V()];
	//m_hasCycle = false;
	//m_onStack = new bool[G.V()];
	//for (int i = 0; i < G.V(); i++)
	//{
	//	m_marked[i] = false;
	//	m_onStack[i] = false;
	//}

	//for (int v = 0; v < G.V(); v++)
	//{
	//	if (m_marked[v] == false)
	//	{
	//		this->dfs(G, v);
	//	}
	//}
}

bool DirectedCycle::hasCycle()
{
	//return this->m_hasCycle;
	return false;
}

void DirectedCycle::dfs(Digraph G, int v)
{
	//m_marked[v] = true;
	//m_onStack[v] = true;
	//while (!G.adj[v].isEmpty())
	//{
	//	if (m_marked[G.adj[v].dequeue()] == false)
	//	{
	//		dfs(G, G.adj[v].dequeue());
	//	}
	//	if (m_onStack[G.adj[v].dequeue()])
	//	{
	//		m_hasCycle = true;
	//		return;
	//	}
	//}
	//m_onStack[v] = false;
}