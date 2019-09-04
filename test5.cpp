/*************************************************************************
  > File Name: test5.cpp
  > Author: liyz
  > Mail: 981530280@qq.com 
  > Created Time: 2019年07月10日 星期三 18时25分01秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <map>
#include <unistd.h>
using namespace std;
string s;

//static char [10][20] = {"0","一","二","三","四","五","六","七","八","九","十"};
map<char, string> mymap;
typedef pair<char,string> mypair;
int insert_chinese(string src, string &dest, int length,int pos){
	string strtmp;
	
	int i = 0;
	for(i = 0; i < src.size();i++){
		map<char, string>::iterator it = mymap.find(src[i]);
		if(it != mymap.end()){
			string temp = it->second;
			strtmp = src.insert(i,temp);
			strtmp.erase(i+3,1);
			break;
		}else{
			strtmp = src;
		}
	}
	if(src.size() == i)
	{
		dest = strtmp;
		return 0;
	}
	cout<<"转化为："<<strtmp<<endl;
	dest = strtmp;
	//usleep(3000 * 1000);
	return insert_chinese(strtmp, dest, strtmp.length(),i);
}
int main() {
	mymap.insert(mypair('1',"一"));
	mymap.insert(mypair('2',"二"));
	mymap.insert(mypair('3',"三"));
	mymap.insert(mypair('4',"四"));
	mymap.insert(mypair('5',"五"));
	mymap.insert(mypair('6',"六"));
	mymap.insert(mypair('7',"七"));
	mymap.insert(mypair('8',"八"));
	mymap.insert(mypair('9',"九"));
	cout<<"请输入一个含大写的字符串：";
	string str,dest;
	cin>>str;
	transform(str.begin(),str.end(),str.begin(),::tolower);
	insert_chinese(str,dest,str.size(),0);
	cout <<"转小成功"<<dest <<endl;
	///转小写
	
	//cout<<"转化为小写后为："<<str<<endl;
	//transform(str.begin(),str.end(),str.begin(),::toupper);
	//cout<<"转化为大写后为："<<str<<endl;

	return 0;
}

