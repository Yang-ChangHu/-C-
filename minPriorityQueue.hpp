#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class minPriorityQueue
{
public:
	minPriorityQueue(int capacity);
	T delMin();
	void insert(T t);
	int size();
	bool isEmpty();

private:
	bool less(int i, int j);
	void exch(int i, int j);
	void swim(int k);
	void sink(int k);

	T* items;
	int N;
};

template<class T>
minPriorityQueue<T>::minPriorityQueue(int capacity)
{
	this->items = new T[capacity+1];
	this->N = 0;
}

template<class T>
T minPriorityQueue<T>::delMin()
{
	T temp = items[1];
	exch(1, N--);
	sink(1);
	return temp;
}

template<class T>
void minPriorityQueue<T>::insert(T t)
{
	items[++N] = t;
	swim(N);
}

template<class T>
int minPriorityQueue<T>::size()
{
	return this->N;
}

template<class T>
bool minPriorityQueue<T>::isEmpty()
{
	return this->N == 0;
}

template<class T>
bool minPriorityQueue<T>::less(int i, int j)
{
	return items[i] < items[j];
}

template<class T>
void minPriorityQueue<T>::exch(int i, int j)
{
	T tmp = items[i];
	items[i] = items[j];
	items[j] = tmp;
}

template<class T>
void minPriorityQueue<T>::swim(int k)
{
	while (k > 1)
	{
		if (less(k, k / 2))
		{
			exch(k, k / 2);
			k = k / 2;
		}
		else
		{
			break;
		}
	}
}

template<class T>
void minPriorityQueue<T>::sink(int k)
{
	while (2*k <=N)
	{
		int minValue;
		if (2 * k + 1 <= N)
		{
			if (less(2 * k, 2 * k + 1))
			{
				minValue=2*k;
			}
			else
			{
				minValue=2*k+1;
			}
		}
		else
		{
			minValue = 2 * k;
		}
		if(less(minValue,k))
		{
			exch(minValue, k);
			k = minValue;
		}
		else
		{
			break;
		}


	}
}
