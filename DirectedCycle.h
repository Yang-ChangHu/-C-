#pragma once
#include<iostream>
#include<string>
#include"Digraph.h"
using namespace std;

class DirectedCycle
{
public:
	DirectedCycle(Digraph G);
	bool hasCycle();
private:
	void dfs(Digraph G, int v);
	
	bool* m_marked;
	bool m_hasCycle;
	bool* m_onStack;
};