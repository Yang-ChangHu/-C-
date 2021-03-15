#pragma once
#include<iostream>
#include<string>
#include"Bubble.hpp"
using namespace std;

template<class T>
class insection :public Bubble<T>
{
	virtual void sort(T* t, int len);
};

template<class T>
void insection<T>::sort(T* t, int len)
{
	for (int i = 1; i < len; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (Bubble<T>::greater(t[j-1], t[j]))
			{
				Bubble<T>::exch(t,j-1, j);
			}
			else
			{
				continue;
			}
		}
	}
}