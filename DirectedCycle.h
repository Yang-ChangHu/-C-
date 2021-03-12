#pragma once
#include<iostream>
#include<string>
#include"Digraph.h"
using namespace std;

class DirectedCycle
{
public:
	DirectedCycle(class Digraph G);
	~DirectedCycle();
	bool hasCycle();
private:
	void dfs(class Digraph G, int v);
	
	bool* m_marked;
	bool m_hasCycle;
	bool* m_onStack;
};