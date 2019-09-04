/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-08-30 15:01:01
 * @LastEditTime: 2019-09-02 14:11:37
 * @LastEditors: Please set LastEditors
 */
#include <iostream>
 #include <typeinfo>
using namespace std;
class base
{
	virtual void f(){}//基类是多态类
};
class Derived1 : public base
{};
class Derived2 : public base
{};
void WhatType(base &ob)
{
	//cout<<"ob is referercing an object of type:"<<typeid(ob).name()<<endl;
	if(typeid(ob) == typeid(Derived1))
	{
		cout << "i am is Derived1" << endl;
	}
}
int main()  
{  
    cout<<"Start"<<endl; 
	
	int i;
	base baseob;
	Derived1 ob1;
	Derived2 ob2;
	WhatType(baseob);
	WhatType(ob1);
	WhatType(ob2);
	
    cout<<"End"<<endl;  
}  