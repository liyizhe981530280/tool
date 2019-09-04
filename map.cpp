/*************************************************************************
	> File Name: map.cpp
	> Author: liyz
	> Mail: 981530280@qq.com 
	> Created Time: 2019年07月02日 星期二 19时20分35秒
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;
int main()
{

	typedef struct data{
		int data;
		int data;
	}ceshi;
    map<int ,ceshi *> mymap;
    for(int i = 0; i < 10; i++){
		ceshi *data = (ceshi *)malloc(sizeof(sizeof(ceshi)));
		data->data = 1;
		data->data = 2;
		mymap.insert(pair<int, ceshi*> (i, data));
	}
	map<int, ceshi>::iterator it;

	for(it = mymap.begin();i t !=)


}
