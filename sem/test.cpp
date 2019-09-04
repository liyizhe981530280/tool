/*************************************************************************
  > File Name: test.cpp
  > Author: liyz
  > Mail: 981530280@qq.com 
  > Created Time: 2019年06月24日 星期一 12时33分44秒
 ************************************************************************/

#include <iostream>
#include <list>
using namespace std;
struct data{
		int i;
};
int main()
{
	
	std::list<struct data* > mylist;
	data a;
	a.i = 1;
	mylist.push_back(&a);
   
	list<struct data*>::iterator it;
	for(it = mylist.begin();it != mylist.end();++it)
	{
		cout << (**it).i<< endl;
	}
	return 0;

}
