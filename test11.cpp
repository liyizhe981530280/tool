/*************************************************************************
	> File Name: test11.cpp
	> Author: liyz
	> Mail: 981530280@qq.com 
	> Created Time: 2019年08月27日 星期二 17时54分26秒
 ************************************************************************/

#include <iostream>
#include <memory>
int main()
{
	std::allocator<int> alloc;
	std::default_delete<int> del;

	std::shared_ptr<int> foo = std::allocate_shared<int>(alloc, 10);

	auto bar = std::allocate_shared<int>(alloc, 20);
	auto baz = std::allocate_shared<std::pair<int, int>> (alloc, 30, 40);

	std::cout << "*foo" << *foo <<"]"<< std::endl;
	std::cout << "*bar" << *bar <<"]" <<std::endl;
	std::cout << "*baz" << baz->first << ' '<< baz->second << "]"<< std::endl;

	return 0;
}

