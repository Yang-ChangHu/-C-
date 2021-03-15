#pragma once
#include<iostream>
#include<string>
#include"Bubble.hpp"
using namespace std;

template<class T>
class Merge:public Bubble<T>
{
public:
	//Merge();
	virtual void sort(T* t, int len);


private:
	void sort(T* a, int lo, int hi);
	void merge(T* a, int lo, int mid, int hi);
	//bool less(T v, T, w);

	T* assist;

};

template<class T>
void Merge<T>::sort(T* t, int len)
{
	assist = new T[len];
	int lo = 0;
	int hi = (len -1);
	Merge<T>::sort(t, lo, hi);

}

template<class T>
void Merge<T>::sort(T* a, int lo, int hi)
{
	if (hi <= lo)
	{
		return;
	}
	int mid = lo + (hi - lo) / 2;
	Merge<T>::sort(a, lo, mid);
	Merge<T>::sort(a, mid+1, hi);
	merge(a, lo, mid, hi);


}


template<class T>
void  Merge<T>::merge(T* a, int lo, int mid, int hi)
{
	int i = lo;
	//T* tmp = new T[hi + 1];
	int p1 = lo;
	int p2 = mid + 1;
	while (p1 <= mid && p2 <= hi)
	{
		if (Bubble<T>::greater(a[p1], a[p2]))
		{
			assist[i] = a[p2];
			p2++;
		}
		else
		{
			assist[i] = a[p1];
			p1++;
		}
		i++;
	}

	while (p1 <= mid)
	{
		assist[i++] = a[p1++];
	}
	while (p2 <= hi)
	{
		assist[i++] = a[p2++];
	}
	for (int i = lo; i <= hi; i++)
	{
		a[i] = assist[i];
	}

}