/*************************************************************************
	> File Name: time.cpp
	> Author: liyz
	> Mail: 981530280@qq.com 
	> Created Time: 2019年07月02日 星期二 20时21分05秒
 ************************************************************************/

#include <iostream>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
	struct timeval currenttime;

	gettimeofday(&currenttime,NULL);

	cout<< currenttime.tv_sec <<endl <<currenttime.tv_usec <<endl;

	long long a = 0;

	cout << sizeof(a) <<endl;
	double b = 0;
	cout << sizeof(b) << endl;

	int c = 0;
	cout << sizeof(c) << endl;

	return 0;

}

