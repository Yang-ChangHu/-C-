#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class Heap
{
public:
	Heap(int capacity);
	T deleMax();
	void insert(T t);
	void ShowMessage() const;
	int getSize() const;

private:
	bool less(int i, int j) const;
	void exch(int i, int j);
	void swim(int k);
	void sink(int k);


	T* items;
	int N;
};

template<class T>
Heap<T>::Heap(int capacity)
{
	//this->items =(T[]) new T[capacity];
	this->items = new T[capacity];
	this->N = 0;
}

template<class T>
bool Heap<T>::less(int i, int j) const
{
	T* arry = this->items;
	return (*(arry+i))< (*(arry + j));
}

template<class T>
void Heap<T>::exch(int i, int j)
{
	T temp = items[i];
	items[i] = items[j];
	items[j] = temp;
}

template<class T>
T Heap<T>::deleMax()
{
	T maX = items[1];
	exch(1, N);
	//delete items[N--];
	sink(1);
	return maX;
}

template<class T>
void Heap<T> ::insert(T t)
{
	items[++N] = t;
	swim(N);
}

template<class T>
void Heap<T>::swim(int k)
{
	while (k > 1)
	{
		if (less(k / 2, k))
		{
			exch(k / 2, k);
		}
		k = k / 2;
	}

}

template<class T>
void Heap<T>::sink(int k)
{
	while ((2*k) < N)
	{
		if ((2 * k + 1) <= N)
		{
			int maX ;
			if (less(2 * k, 2 * k + 1))
			{
				maX = 2 * k + 1;
			}
			else
			{
				maX = 2 * k;
			}
			if (!less(k, maX))
			{
				break;
			}
			else 
			{
				T tmp = items[maX];
				items[maX] = items[k];
				items[k] = tmp;
				k = maX;
			}
		}
	}
}

template<class T>
void Heap<T>::ShowMessage() const
{
	T* arry = items;
	for (int i = 1; i <= N; i++)
	{
		cout <<"\t第"<<i<<"\t个元素事："<< *(arry) << endl;
		arry++;
	}
}

template<class T>
int Heap<T>::getSize() const
{
	return N;
}