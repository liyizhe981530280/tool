/*************************************************************************
  > File Name: throw.cpp
  > Author: liyz
  > Mail: 981530280@qq.com 
  > Created Time: 2019年08月10日 星期六 10时05分53秒
 ************************************************************************/

#include <iostream>
using namespace std;

int divide(int x, int y)
{
	if(y == 0)
	{
		throw('a');
	}
	return x/y;
}

class A{
	public:
		A()
		{
			cout << "A constructor" << endl;
		}
		A(const A &)
		{
			cout << "A copy constructor" << endl;
		}
		~A()
		{
			cout << "~A destructor" << endl;
		}
};


int divide1(int x, int y)
{
	A a;
	if(y == 0)
	{
		throw('a');
	}
	return x/y;
}

int myDivide(int x, int y)
{
	A b;
	divide1(x, y);
}

int main()
{
	try{
		myDivide(4,0);
	}catch(int x)
	{
		cout<< "x" <<endl;
		cout << x << endl;
	}catch(double y)
	{
		cout << "y" << endl;
		cout << y << endl;
	}
	catch(const A &a){
		cout << "hello world" << endl;
	}

	return 0;

}
