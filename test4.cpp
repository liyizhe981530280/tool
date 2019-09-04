/*************************************************************************
	> File Name: test4.cpp
	> Author: liyz
	> Mail: 981530280@qq.com 
	> Created Time: 2018年11月09日 星期五 10时07分01秒
 ************************************************************************/

#include <iostream>
#include <thread>
using namespace std;
#if 0
void hello()
{
	std::cout << "hello Current world";
}
std::thread t({
	hello();
});
#endif
void trim(std::string &data)
{
    int index = 0;
    if(!data.empty()){
       while( (index = data.find(' ',index)) != string::npos)
       {
             data.erase(index,1);         
	   }
    }
}
class A{
   public:
      void aa()
	  {
		  cout << "i am father!" << endl;
	  }
};

class b : public A{
	public:
	  void aa(){
		  cout << "i am boy!" << endl;
	  }
};
int main(){
	//thread t;
	//t = new thread()

	string data = " 安朗杰门锁模块";
	trim(data);
	cout<< data << endl;

	b c;
	c.aa();
	return 0;
}

