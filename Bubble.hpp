#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class Bubble
{
public:
	virtual void sort(T* t,int len);
	void showMessage(T* t,int len);
protected:
	bool greater(T t1, T t2);
	void exch(T* t, int i, int j);
};

template<class T>
void  Bubble<T>::sort(T* t,int len)
{
	for (int i = len - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (greater(t[j], t[j + 1]))
			{
				exch(t, j, j + 1);
			}
			else
			{
				continue;
			}
		}
	}
}
template<class T>
bool Bubble<T>::greater(T t1, T t2)
{
	return t1 > t2;
}


template<class T>
void Bubble<T>::exch(T* t, int i, int j)
{
	T tmp = t[i];
	t[i] = t[j];
	t[j] = tmp;
}

template<class T>
void Bubble<T>::showMessage(T* t,int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << t[i] << " ";
	}
	cout << endl;
}