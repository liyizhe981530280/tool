/*************************************************************************
	> File Name: const.cpp
	> Author: liyz
	> Mail: 981530280@qq.com 
	> Created Time: 2018年12月13日 星期四 15时07分53秒
 ************************************************************************/

#include <iostream>
using namespace std;

class A
{
  public:
	A()
	{
		m_iNum = 0;
	}

  public:
	int m_iNum;
};

void foo()
{
	//1. 指针指向类
	const A *pca1 = new A;
	A *pca2 = const_cast<A *>(pca1); ////常量对象转换为非常量对象
	pca2->m_iNum = 200;
	//转换后指针指向原来的对象
	cout << pca1->m_iNum << pca2->m_iNum << endl;

	//2. 指针指向基本类型
	const int ica = 100;
	int *ia = const_cast<int *>(&ica);
	*ia = 200;
	cout << *ia << ica << endl;
}


void foo1(){
	const A *pca = new A;
	A *pca1 = const_cast<A*>(pca);
	pca1->m_iNum = 200;
	cout<<pca->m_iNum << "dd" << pca1->m_iNum <<endl;
}
int main()
{
	foo1();
	cout << "hello world" << endl;
	return 0;
}
