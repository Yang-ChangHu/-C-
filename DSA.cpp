#include<iostream>
#include<string>
#include"arrayList.hpp"
#include"LinearList.h"
#include"myclass.h"
#include"chain.hpp"
using namespace std;


//全局函数重载左移运算法 方便打印
void operator<<(ostream &cout,Person p)
{
	cout << "姓名：" << p.m_name << "   年龄： " << p.m_age << endl;
}

//全局函数重载等号运算法方便比较
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
	Person p1(18, "张三");
	Person p2(19, "李四");
	Person p3(20, "王五");
	Person p4(21, "赵六");
	Person p5(22, "周七");

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
	Person p1(18, "张三");
	Person p2(19, "李四");
	Person p3(20, "王五");
	Person p4(21, "赵六");
	Person p5(22, "周七");
	Person p6(5, "王八蛋");


	chain<Person> c(3);
	c.insert(0, p1);
	c.insert(1, p2);
	c.insert(2, p3);
	c.insert(3, p4);
	c.insert(4, p5);
	//c.ShowMessage();

	cout<<"位置是："<<c.indexOf(p5)<<endl;
	c.ShowMessage();
}

int main()
{
	test02();
	system("pause");
	return 0;
}