#include<iostream>
#include<string>
#include"UFtreeWeight.h"
using namespace std;

UFtreeWeight::UFtreeWeight(int n)
{
	this->countn = n;
	this->eleAndGroup = new int[n];
	this->sz = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		eleAndGroup[i] = i;
		sz[i] = 1;
	}

}
int UFtreeWeight::count()
{
	return countn;
}

int UFtreeWeight::find(int p)
{
	//int number = 1;
	while (true)
	{
		if (this->eleAndGroup[p] == p)
		{
			//sz[p] = number;
			return p;
		}
		else
		{
			p = eleAndGroup[p];
			//number++;
		}
	}
}

bool UFtreeWeight::connected(int p, int q)        //bool connnected(int p, int q);
{
	return find(p) == find(q);
}

void UFtreeWeight::myunion(int p, int q)
{

	int proot = find(p);
	int qroot = find(q);
	if (proot == qroot)
	{
		return;
	}

	if (sz[proot] < sz[qroot])
	{
		eleAndGroup[proot] = qroot;
		sz[qroot] += sz[proot];
		sz[proot] = 0;
	}
	else
	{
		eleAndGroup[qroot] = proot;
		sz[proot] += sz[qroot];
		sz[qroot] = 0;
	}

	this->countn--;
}

void UFtreeWeight::showMessage(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << sz[i] << " ";
	}
	cout << endl;
}