/*************************************************************************
  > File Name: pthread1.cpp
  > Author: liyz
  > Mail: 981530280@qq.com 
  > Created Time: 2019年08月29日 星期四 11时21分20秒
 ************************************************************************/

#include <iostream>
#include <pthread.h>
#include <stdio.h>
using namespace std;

class test{
	public:
	    test();
		~test();
		int a;
		void start();
	private:
		pthread_t pth;
		static void *myprintf(void *arg);
	
};
test::test()
{
	cout << "我是构造函数";
}
test::~test()
{
	cout << "我是析构函数";
}
void *test::myprintf(void *arg)
{
	printf("hello world\n");
}
void test::start(){
	pthread_create(&pth,NULL, myprintf,NULL);
}
int main()
{
	test w;
	w.start();
	cout << "hello world" << endl;
	return 0;
}
