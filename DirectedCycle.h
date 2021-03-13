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
	bool hasCycle() const;
private:
	void dfs(class Digraph G, int v) const;
	
	bool* m_marked;
	mutable bool m_hasCycle;
	bool* m_onStack;
};