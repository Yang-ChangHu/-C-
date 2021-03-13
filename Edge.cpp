#include"Edge.h"
#include<iostream>
#include<string>
using namespace std;

Edge::Edge(int v, int w, double weight)
{
	this->v = v;
	this->w = w;
	this->weight = weight;
}

Edge::Edge()
{
	this->v = 0;
	this->w = 0;
	this->weight = 0;
}

double Edge::Weight() const
{
	return weight;
}
int Edge::Either() const
{
	return v;
}
int Edge::Other(int vertex) const
{
	if (vertex == v)
	{
		return w;
	}
	else
	{
		return v;
	}
}
int Edge::CompareTo(Edge that) const
{
	if (this->weight > that.weight)
	{
		return 1;
	}
	else if (this->weight < that.weight)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}