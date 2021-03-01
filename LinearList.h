#pragma once
#include<iostream>
#include <fstream>
using namespace std;


template<class T>
class linearList
{
public:
	virtual ~linearList()=0;
	virtual bool empty()const = 0;
	//当线性表为空时返回true

	virtual int size()const = 0;
	//返回线性表元素个数

	virtual T& get(int theIndex) const= 0;
	//返回索引为theIndex的元素

	virtual int indexOf(const T& theElement) const= 0;
	//返回元素theElement第一次出现的索引

	virtual void erase(int theIndex) = 0;
	//删除索引为theIndex的元素

	virtual void insert(int theIndex, const T& theElement) = 0;
	//把元素theElement插入索引为theIndex的地方

	void changeLength1D(T*& a, int oldlength, int newlength);

	virtual void ShowMessage() = 0;

};

template<class T>
void linearList<T>::changeLength1D(T*& a, int oldlength, int newlength)  //这种沙雕用法参见https://blog.csdn.net/u011334621/article/details/48050399
{
	T* tmp = new T[newlength];
	int number = min(oldlength, newlength);
	copy(a, a + number, tmp);
	delete[] a;
	a = tmp;
}


template<class T>
linearList<T>::~linearList()
{
	cout << "Animal 纯虚析构函数调用！" << endl;
}
