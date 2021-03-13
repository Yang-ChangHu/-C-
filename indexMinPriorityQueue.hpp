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
	
	//Ĭ������£�������û�д��κ����ݣ�Ĭ���������qp�е�Ԫ�ض�Ϊ-1
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


//�ж�����i����ֵ�Ƿ�С������j����ֵ
template<class T>
bool IndexMinPriorityQueue<T>::less(int i, int j) const
{
	return items[pq[i]] < items[pq[j]];
}

template<class T>
void IndexMinPriorityQueue<T>::exch(int i, int j)
{
	//����pq�е�����
	int tmp = pq[i];
	pq[i] = pq[j];
	pq[j] = tmp;

	//����qp�е�����
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
void IndexMinPriorityQueue<T>::mydelete(int i)//�����ɾ��items������Ϊi��Ԫ��
{
	//�ҵ�i��pq�е�����
	int k = qp[i];

	//����pq��k��������ֵ��N��������ֵ
	exch(k, N);

	//ɾ��qp�е�����
	qp[pq[N]] = -1;

	//ɾ��pq�е�����
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