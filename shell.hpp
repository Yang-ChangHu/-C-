#pragma once
#include<iostream>
#include<string>
#include"Bubble.hpp"
using namespace std;

template<class T>
class shell :public Bubble<T>
{
	virtual void sort(T* t, int len);
private:
	int h;
};

template<class T>
void shell<T>::sort(T* t, int len)
{
	int h = 1;
	while (h < len / 2)
	{
		h = 2 * h + 1;
	}
	while (h >= 1)
	{
		for (int i = h; i < len; i ++)
		{
			for (int j = i; j >= h; j -= h)
			{
				if (Bubble<T>::greater(t[j - h], t[j]))
				{
					Bubble<T>::exch(t,j, j - h);
				}
				else
				{
					continue;
				}
			}
		}
		h = h / 2;
	}
}


