#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T1,class T2>
class symbolchainNode 
{
public:
	T1 key;
	T2 value;
	symbolchainNode<T1, T2>* next;

	//symbolchainNode();
	symbolchainNode(T1 key, T2 value, symbolchainNode<T1, T2>* next);
};


template<class T1,class T2>
symbolchainNode<T1, T2>::symbolchainNode(T1 key, T2 value, symbolchainNode<T1, T2>* next)
{
	this->key = key;
	this->value = value;
	this->next = next;
}