/*************************************************************************
	> File Name: test1.cpp
	> Author: liyz
	> Mail: 981530280@qq.com 
	> Created Time: 2018年11月06日 星期二 17时21分39秒
 ************************************************************************/

#include <iostream>
using namespace std;
class Point{
	public:
		void init(){}
    static void output()
	{
		cout << "hello";
	}
};

int main()
{
//	Point::init();
	Point::output();
	return 0;
}
