#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class MaxPriorityQueue
{
	

public:
	MaxPriorityQueue(int capacity);
	T delMax();
	void insert(T t);
	void swim(int k);
	void sink(int k);
	int size() const;
	bool isEmpty() const;

private:
	bool less(int i, int j) const;
	void exch(int i, int j);


	T* items;
	int N;
};

template<class T>
MaxPriorityQueue<T>::MaxPriorityQueue(int capacity)
{
	items = new T[capacity+1];
	this->N = 0;
}
template<class T>
int MaxPriorityQueue<T>::size() const
{
	return this->N;
}


template<class T>
bool MaxPriorityQueue<T>::isEmpty() const
{
	return this->N==0;
}


template<class T>
bool MaxPriorityQueue<T>::less(int i,int j) const
{
	return (this->items[i])<(this->items[j]);
}


template<class T>
void MaxPriorityQueue<T>::exch(int i, int j)
{
	T temp = (this->items[i]);
	(this->items[i]) = (this->items[j]);
	(this->items[j]) = temp;
}

template<class T>
void MaxPriorityQueue<T>::insert(T t)
{
	items[++N] = t;
	swim(N);

}

template<class T>
T MaxPriorityQueue<T>::delMax()
{
	T maxvalue = items[1];
	exch(1, N);
	//items[N--].~T();
	N--;
	sink(1);
	return maxvalue;

}

template<class T>
void MaxPriorityQueue<T>::swim(int k)
{
	while (k>1)
	{
		if (less(k/2,k))
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
void MaxPriorityQueue<T>::sink(int k)
{
	while (2*k<=N)
	{
		int maxIndex;
		if (2 * k + 1 <= N)
		{
			if (less(2 * k, 2 * k + 1))
			{
				maxIndex = 2 * k + 1;
			}
			else
			{
				maxIndex = 2 * k;
			}
		}
		else
		{
			maxIndex = 2 * k;

		}
		if (less(k, maxIndex))
		{
			exch(k, maxIndex);
			k = maxIndex;
		}
		else
		{
			break;
		}
	}
}