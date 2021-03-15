#pragma once
#include<iostream>
#include<string>
#include"Bubble.hpp"
using namespace std;

template<class T>
class Quick:public Bubble<T>
{
public:
	virtual void sort(T* t, int len);
	void sort(T* t, int lo, int hi);
	int partion(T* t, int lo, int hi);

};


template<class T>
void Quick<T>::sort(T* t, int len)
{
	int lo = 0;
	int hi = len-1 ;
	sort( t, lo, hi);
}

template<class T>
void Quick<T>::sort(T* t, int lo, int hi)
{
	if (hi <= lo)
	{
		return;
	}
	int partition = partion(t, lo, hi);

	Bubble<T>::showMessage(t,6);

	sort(t, lo, partition - 1);

	Bubble<T>::showMessage(t,6);

	sort(t, partition + 1, hi);

	Bubble<T>::showMessage(t,6);

}
template<class T>
int  Quick<T>::partion(T* t, int lo, int hi)
{
	int left = lo+1;
	int right = hi+1 ;
	T key = t[lo];
	while (1)
	{
		if (right == left)
		{
			Bubble<T>::exch(t, right, lo);
			return right;
		}
		else
		{
			while (Bubble<T>::greater(t[--right], key))
			{
				//right++;
			}
			while (Bubble<T>::greater(key, t[++left]))
			{
				//right++;
			}
			Bubble<T>::exch(t, right, left);

		}
	}

}
