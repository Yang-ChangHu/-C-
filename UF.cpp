#include<iostream>
#include<string>
#include"UF.h"
using namespace std;

UF::UF(int n)
{
	this->countn = n;
	this->eleAndGroup = new int[n];
	for (int i = 0; i < n; i++)
	{
		eleAndGroup[i] = i;
	}

}
int UF::count()
{
	return countn;
}

int UF::find(int p)
{
	return eleAndGroup[p];
}

bool UF::connected(int p, int q)
{
	return find(p) == find(q);
}

void UF::myunion(int p, int q)
{
	if (connected(p, q))
	{
		return;
	}
	int pGroup = find(p);
	int qGroup = find(p);
	for (int i = 0; i < (sizeof(eleAndGroup) / (sizeof(eleAndGroup[0]))); i++)
	{
		if (eleAndGroup[i] == pGroup)
		{
			eleAndGroup[i] = qGroup;
		}
	}
	this->countn--;
}