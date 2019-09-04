/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-08-29 15:30:53
 * @LastEditTime: 2019-08-29 15:37:32
 * @LastEditors: Please set LastEditors
 */
/*************************************************************************
	> File Name: for_each.cpp
	> Author: liyz
	> Mail: 981530280@qq.com 
	> Created Time: 2019年04月01日 星期一 10时32分41秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(int &elem)
{
	cout << elem << endl;
}

void InitStata(initializer_list<void *> list)
{
	vector<pair<void *, int>> priData;
	std::for_each(list.begin(), list.end(), [&](void *const &item) {priData.push_back({item, 1});});
	cout << priData.size();
}
int main()
{
	int ia[] = {1, 2, 3};

	//vector<int> ivec(ia, ia + sizeof(ia) / sizeof(int));

	//for_each(ivec.begin(), ivec.end(), print);
	void *dev,*led,*first;
     InitStata({dev,led,first});
	return 0;
}
