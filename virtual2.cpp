/*************************************************************************
  > File Name: virtual1.cpp
  > Author: liyz
  > Mail: 981530280@qq.com 
  > Created Time: 2019年08月09日 星期五 11时24分24秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <list>
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

int main()
{
/*	Base *base = nullptr;
	Child1 chid;
	base = &chid;
	myprintf(base);
	*/


	//list<Base> mylist;
	//list<Base>::iterator it;

    //Child1 *ld1 = new Child1();

	//mylist.insert()

    //for(it = mylist.begin(); it != mylist.end(); ++it)
//	{
		
//	}

     Base *base = nullptr;
	 base = new Child1();
	 base->disp();
	 delete base;
	return 0;
}
