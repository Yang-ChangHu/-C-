#pragma once
#include"Graph.h"
#include<iostream>
#include<string>
using namespace std;
class BreadthFirstSearch
{
public:
	BreadthFirstSearch(Graph G, int s);
	bool Marked(int w);
	int Count();
private:
	void bfs(Graph G, int s);

	bool* marked;
	int count;
	queue<int> waitSearch;

};