#pragma once

#include <sstream>
#include"LinearList.h"
#include<iostream>
#include <algorithm>
using namespace std;



//顺序表
template<class T>
class arrayList :public linearList<T>
{
public:
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T>&);
	~arrayList()
	{
		delete [] element;
		element = NULL;
	}

	bool empty() const
	{
		return listSize == 0;
	}
	int size() const
	{
		return listSize;
	}

	T& get(int theIndex) const;

	int indexOf(const T& theElement) const;

	void erase(int theIndex);

	void insert(int theIndex, const T& theElement);


	int capacity() const
	{
		return arrayLength;
	}

	//显示当前顺序表信息
	void ShowMessage();

protected:
	

	T* element;//储存线性表元素的一维数组
	int arrayLength;//一维数组容量
	int listSize;  //线性表的元素个数
};

template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
	if (initialCapacity < 1)
	{

		cout << "Initial capacity  must be>0" << endl;
	}
	arrayLength = initialCapacity;
	element = new T[arrayLength];
	listSize = 0;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
	element = new T[arrayLength];
	copy(theList.element, theList.element + listSize, element);
}

template<class T>
T& arrayList<T>::get(int theIndex) const
{
	if (theIndex<0 || theIndex>listSize)
	{
		cout << "你输入的数不对" << endl;

	}
	return element[theIndex];
}
template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{
	int theIndex = (int)(find(element, element + listSize, theElement) - element);
	if (theIndex == listSize)
	{
		return -1;
	}
	return theIndex;
}

template<class T>
void arrayList<T>::erase(int theIndex)
{
	copy(element + theIndex + 1, element + listSize, element + theIndex);
	element[--listSize].~T();
}

template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
	if (listSize == arrayLength)
	{
		linearList<T>::changeLength1D(element, arrayLength, 2 * arrayLength);
	}
	copy_backward(element + theIndex, element + listSize, element + listSize + 1);
	element[theIndex] = theElement;
	listSize++;
}

template<class T>
void arrayList<T>::ShowMessage()
{
	cout << "当前容量：" << arrayLength << "  当前元素个数:" << listSize << endl;
	for (int i = 0; i < listSize; i++)
	{
		cout << element[i];
	}
}
