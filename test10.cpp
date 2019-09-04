/*************************************************************************
  > File Name: test10.c
  > Author: liyz
  > Mail: 981530280@qq.com 
  > Created Time: 2019年08月27日 星期二 17时01分31秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
using namespace std; 
int main()
{
	int ret = -1;
	if(!ret)
	{
		printf("this \n");
	}else {
		printf("tttt\n");
	}
	//char *p = new char[100];
	shared_ptr<string> psr;
//	psr ('aaaaaaaaaaaaaaaaaaaaaa');
//	psr = make_shared<string>("ddddddddd");
	psr->append("ddddddddd");
	//strcpy(psr,"ddddddddd");

	//printf("oooooooo%s\n",psr);
	//

//	cout << "----" << psr;


	return 0;
}

