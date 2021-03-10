#include<iostream>
#include<string>
#include"UFtree.h"
using namespace std;

UFtree::UFtree(int n)
{
	this->countn = n;
	this->eleAndGroup = new int[n];
	for (int i = 0; i < n; i++)
	{
		eleAndGroup[i] = i;
	}

}
int UFtree::count()
{
	return countn;
}

int UFtree::find(int p)
{
	while (true)
	{
		if (this->eleAndGroup[p] == p)
		{
			return p;
		}
		else
		{
			p = eleAndGroup[p];
		}
	}
}

bool UFtree::connected(int p, int q)        //bool connnected(int p, int q);
{
	return find(p) == find(q);
}

void UFtree::myunion(int p, int q)
{

	int proot = find(p);
	int qroot = find(q);
	if (proot == qroot)
	{
		return;
	}

	eleAndGroup[proot] = qroot;
	this->countn--;
}