/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-08-30 11:26:12
 * @LastEditTime: 2019-08-30 14:54:17
 * @LastEditors: Please set LastEditors
 */

#include <iostream>
#include <stdio.h>
 #include <typeinfo>
using namespace std;

class Base{
	public:
		virtual void disp()
		{
			cout << "this is Base" << endl;
		}
};

class Child1 : public Base{
	public:
		void disp()
		{
			cout << "this is child1" << endl;
		}
};

class Child2 : public Base{
	public:
		void disp()
		{
			cout << "this is child2" << endl;
		}

};

void myprintf(Base *base)
{
	base->disp();
}
#include <list>
class  BaseA{};
class  DeriveA:public BaseA{};
class BaseB{
	virtual void f() {}
};
class DeriveB:public BaseB{};
#define OUTPUT(f)	cout << #f << "\t: " << typeid(f).name() << endl;
int main()
{
	//Base *base = nullptr;
	//Child1 chid;
	//base = &chid;
	//myprintf(base);
	#if 0
     cout << "直接处理类名" << endl;
    OUTPUT(BaseA);
	OUTPUT(DeriveA);
	OUTPUT(BaseB);
	OUTPUT(DeriveB);
	cout << endl << "-------基类不含虚函数-------" <<endl;
 
	BaseA baseA;
	DeriveA deriveA;
	OUTPUT(baseA);
	OUTPUT(deriveA);
	
	BaseA* pa;
	pa = &baseA;
	OUTPUT(*pa);
	OUTPUT(pa);
	pa = &deriveA;
	OUTPUT(*pa);
	OUTPUT(pa);
 
	cout << endl << "-------基类含有虚函数-------" <<endl;
 
	BaseB baseB;
	DeriveB deriveB;
	OUTPUT(baseB);
	OUTPUT(deriveB);
 
	BaseB* pb;
	pb = &baseB;
	OUTPUT(*pb);
	OUTPUT(pb);
	pb = &deriveB;
	OUTPUT(*pb);
	OUTPUT(pb);
	#endif 

	list<BaseA > mylist;
	DeriveA A;
	mylist.push_back(A);

    list<BaseA>::iterator it;
	for(it = mylist.begin(); it != mylist.end();++it)
	{

		
		std::cout << typeid(*it).name()<< endl;
		// Foo<decltype(f)>()
		//decltype(*it) c;
		//std::cout<< typeid(c).name() << endl;
	}

	const int a = 10, &b = a;
    auto e = a;
    auto d = b;
	
    DeriveA c;
    DeriveA s;
    cout << typeid(a).name() << endl; // int
    cout << typeid(&b).name() << endl;// int const *
    cout << typeid(e).name() << endl; // int
    cout << typeid(d).name() << endl; // int
    cout << typeid(c).name() << endl; // class MyClass
    cout << typeid(s).name() << endl; // Struct MyStruct
	return 0;
}
