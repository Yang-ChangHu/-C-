#pragma once
#include<iostream>
#include<string>
#include"Bubble.hpp"
using namespace std;


template<class T>
class selection :public Bubble<T>
{
	virtual void sort(T* t, int len);
};

template<class T>
void selection<T>::sort(T* t, int len)
{
	for (int i = 0; i < len; i++)
	{
		int minvalue = i;
		for (int j = i; j < len; j++)
		{
			if (Bubble<T>::greater(t[minvalue], t[j]))
			{
				minvalue = j;
			}
			else
			{
				continue;
			}
		}
		Bubble<T>::exch(t, i, minvalue);
	}
}