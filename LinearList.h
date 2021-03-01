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
	//�����Ա�Ϊ��ʱ����true

	virtual int size()const = 0;
	//�������Ա�Ԫ�ظ���

	virtual T& get(int theIndex) const= 0;
	//��������ΪtheIndex��Ԫ��

	virtual int indexOf(const T& theElement) const= 0;
	//����Ԫ��theElement��һ�γ��ֵ�����

	virtual void erase(int theIndex) = 0;
	//ɾ������ΪtheIndex��Ԫ��

	virtual void insert(int theIndex, const T& theElement) = 0;
	//��Ԫ��theElement��������ΪtheIndex�ĵط�

	void changeLength1D(T*& a, int oldlength, int newlength);

	virtual void ShowMessage() = 0;

};

template<class T>
void linearList<T>::changeLength1D(T*& a, int oldlength, int newlength)  //����ɳ���÷��μ�https://blog.csdn.net/u011334621/article/details/48050399
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
	cout << "Animal ���������������ã�" << endl;
}
