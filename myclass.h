#pragma once

#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	int m_age;
	string m_name;

	Person(int age,string name);
	Person();
};

Person::Person(int age, string name)
{
	m_age = age;
	m_name = name;
}

Person::Person()
{

}