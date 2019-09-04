/*************************************************************************
	> File Name: fucntion.cpp
	> Author: liyz
	> Mail: 981530280@qq.com 
	> Created Time: 2019年08月10日 星期六 11时22分43秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
void func(int n)
{
	std::cout << n << std::endl;
}

int f(int a, int b)
{
	return a + b;
}
int main()
{
//	std::vector<int> arr;
//	arr.push_back(1);
//	arr.push_back(2);
//	std::for_each(arr.begin(), arr.end(),func);

	std::function<int(int, int)>func = f;
	cout << f(1,20) << endl;

	std::function<void()> func_1 = [](){cout << "hello world" << endl;};
	func_1();
	return 0;
}
