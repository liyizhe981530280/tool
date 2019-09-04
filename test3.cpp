/*************************************************************************
	> File Name: test3.cpp
	> Author: liyz
	> Mail: 981530280@qq.com 
	> Created Time: 2019年07月10日 星期三 18时15分00秒
 ************************************************************************/

#include <iostream>
using namespace std;
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
void mytolower(char *s){
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            s[i]=tolower(s[i]);
            //s[i]+=32;//+32转换为小写
            //s[i]=s[i]-'A'+'a';
        }
    }
}
void mytoupper(char *s){
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]>='a'&&s[i]<='z'){
            s[i]=toupper(s[i]);
            //s[i]-=32;//+32转换为小写
            //s[i]=s[i]-'a'+'A';
        }
    }
}
 
int main() {
    cout<<"请输入一个含大写的字符串：";
    char s[201];
    gets(s);
    ///转小写
 
    mytolower(s);
    cout<<"转化为小写后为："<<s<<endl;
    mytoupper(s);
    cout<<"转化为大写后为："<<s<<endl;
    return 0;
}
