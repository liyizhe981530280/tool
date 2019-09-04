/*************************************************************************
	> File Name: test2.cpp
	> Author: liyz
	> Mail: 981530280@qq.com 
	> Created Time: 2019年06月22日 星期六 14时50分42秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;


int main()
{
   int size = 64;
   int index = 1;
  // if((index < 0) || (index > size - 1))
    if((index < 0) || (index > size - 1)){
        printf("--------------------%d---%d\n",size,index);
        return 1;
    }
   cout << "helloworld" << endl;
   return 0;
}
