/*************************************************************************
	> File Name: thread1.cpp
	> Author: liyz
	> Mail: 981530280@qq.com 
	> Created Time: 2018年12月13日 星期四 10时05分52秒
 ************************************************************************/

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include<typeinfo>
typedef std::lock_guard<std::mutex> MutexLockGuard;
typedef std::unique_lock<std::mutex> UniqueLock;

class Func
{
	int i;
	std::mutex &m;

  public:
	Func(int i_, std::mutex &m_):
	i(i_), m(m_)
	{
	}
	void operator() ()
	{
		UniqueLock lk(m);
		for (unsigned j = 0; j < 10; j++)
		{
			std::cout << i << "";
		}

		std::cout << std::endl;
	}
};
using namespace std;
int main(int argc, char const *argv[])
{
	std::mutex m;
	std::vector<std::thread> threads;
     std::vector<std::thread>::iterator it;
	for (int i = 1; i < 10; i++)
	{
		Func f(i, m);
		threads.push_back(std::thread(f));
	}
//	for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join)); // 对每个线程调用join()
	for(it = threads.begin();it != threads.end();++it){
		std::mem_fn(&std::thread::join);
	}
	return 0;
}
