#include<iostream>
#include<string>
#include"arrayList.hpp"
#include"LinearList.h"
#include"myclass.h"
#include"chain.hpp"
using namespace std;


//ȫ�ֺ��������������㷨 �����ӡ
void operator<<(ostream &cout,Person p)
{
	cout << "������" << p.m_name << "   ���䣺 " << p.m_age << endl;
}

//ȫ�ֺ������صȺ����㷨����Ƚ�
bool operator==(Person p1, Person p2)
{
	return ((p1.m_age == p2.m_age) && (p1.m_name == p2.m_name));
}

bool operator!=(Person p1, Person p2)
{
	return ((p1.m_age != p2.m_age)|| (p1.m_name != p2.m_name));
}

void test01()
{

	arrayList<Person> p(12);
	//p.ShowMessage();
	Person p1(18, "����");
	Person p2(19, "����");
	Person p3(20, "����");
	Person p4(21, "����");
	Person p5(22, "����");

	p.insert(0, p1);
	p.insert(1, p2);
	p.insert(2, p3);
	p.insert(3, p4);
	p.insert(4, p5);

	p.ShowMessage();
	
	//p.ShowMessage();
	cout<<p.indexOf(p2);

}
void test02()
{

	arrayList<Person> p(12);
	//p.ShowMessage();
	Person p1(18, "����");
	Person p2(19, "����");
	Person p3(20, "����");
	Person p4(21, "����");
	Person p5(22, "����");
	Person p6(5, "���˵�");


	chain<Person> c(3);
	c.insert(0, p1);
	c.insert(1, p2);
	c.insert(2, p3);
	c.insert(3, p4);
	c.insert(4, p5);
	//c.ShowMessage();

	cout<<"λ���ǣ�"<<c.indexOf(p5)<<endl;
	c.ShowMessage();
}

int main()
{
	test02();
	system("pause");
	return 0;
}