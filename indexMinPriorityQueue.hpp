#pragma once
#include<string>
#include<iostream>
using namespace std;

template<class T>
class IndexMinPriorityQueue
{
public:
	IndexMinPriorityQueue(int capacity);
	int delMin();
	void insect(int i, T t);
	int size() const;
	bool isEmpty() const;
	void changeItem(int i, T t);
	bool contains(int k) const;
	int minIndex() const;
	void mydelete(int i);


private:

	void swim(int k);
	void sink(int k);
	bool less(int i, int j) const;
	void exch(int i, int j);

	T* items;
	int* pq;
	int* qp;
	int N;

};

template<class T>
IndexMinPriorityQueue<T>::IndexMinPriorityQueue(int capacity)
{
	items = new T[capacity+1];
	pq = new int[capacity+1];
	qp = new int[capacity+1];
	this->N = 0;
	
	//默认情况下，队列中没有存任何数据，默认情况下让qp中的元素都为-1
	for (int i = 0; i < capacity + 1; i++)
	{
		qp[i]=-1;
	}
}

template<class T>
int IndexMinPriorityQueue<T>::size() const
{
	return this->N;
}

template<class T>
bool IndexMinPriorityQueue<T>::isEmpty() const
{
	return this->N == 0;
}


//判断索引i处的值是否小于索引j处的值
template<class T>
bool IndexMinPriorityQueue<T>::less(int i, int j) const
{
	return items[pq[i]] < items[pq[j]];
}

template<class T>
void IndexMinPriorityQueue<T>::exch(int i, int j)
{
	//交换pq中的数据
	int tmp = pq[i];
	pq[i] = pq[j];
	pq[j] = tmp;

	//更新qp中的数据
	qp[pq[i]] = i;
	qp[pq[j]] = j;

}

template<class T>
bool IndexMinPriorityQueue<T>::contains(int k) const
{
	return qp[k] != -1;
}

template<class T>
int IndexMinPriorityQueue<T>::minIndex() const
{
	return pq[1];
}

template<class T>
void IndexMinPriorityQueue<T>::insect(int i, T t)
{
	if (contains(i))
	{
		return;
	}
	N++;
	items[i] = t;
	pq[N] = i;
	qp[i] = N;

	swim(N);

}

template<class T>
int IndexMinPriorityQueue<T>::delMin()
{
	int minIndex = pq[1];
	exch(1, N--);
	qp[minIndex] = -1;
	items[pq[N]].~T();

	sink(pq[1]);
	return minIndex;
}

template<class T>
void IndexMinPriorityQueue<T>::mydelete(int i)//这个是删除items中索引为i的元素
{
	//找到i在pq中的索引
	int k = qp[i];

	//交换pq中k索引处的值和N索引处的值
	exch(k, N);

	//删除qp中的内容
	qp[pq[N]] = -1;

	//删除pq中的内容
	//items[pq[N]].~T();
	pq[N] = -1;
	N--;
	swim(k);
	sink(k);

}

template<class T>
void IndexMinPriorityQueue<T>::changeItem(int i, T t)
{
	items[i] = t;
	swim(pq[qp[i]]);
	sink(pq[qp[i]]);
}


template<class T>
void IndexMinPriorityQueue<T>::swim(int k)
{
	while (k>1)
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
void IndexMinPriorityQueue<T>::sink(int k)
{
	while (2 * k <= N)
	{
		int minvalue;
		if (2 * k + 1 <= N)
		{
			if (less(2 * k, 2 * k + 1))
			{
				minvalue = 2 * k;
			}
			else
			{
				minvalue = 2 * k + 1;
			}
		}
		else
		{
			minvalue = 2 * k;
		}
		if (less(k, minvalue))
		{
			exch(k, minvalue);
			k = minvalue;
		}
		else
		{
			break;
		}
		
	}
}