#pragma once
#include<iostream>
#include<string>
using namespace std;

//������ڵ���
template<class T>
class chainNode
{
public:
	T element;
	chainNode<T>* next;

	chainNode()
	{

	}

	chainNode(T element ,chainNode<T>* next)
	{
		this->element = element;
		this->next = next;
	}
	~chainNode()
	{
		cout << "chainNode������������" << endl;
		/*delete next;
		next = NULL;*/
	}
};