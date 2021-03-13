#pragma once
#include<iostream>
#include<string>
using namespace std;

class Edge 
{
public:
	Edge(int v, int w, double weight);
	Edge();
	double Weight() const;
	int Either() const;
	int Other(int vertex) const;
	int CompareTo(Edge that) const;

private:
	int v;
	int w;
	double weight;

};
