/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-08-30 16:03:08
 * @LastEditTime: 2019-08-30 16:06:29
 * @LastEditors: Please set LastEditors
 */
#include <iostream>
using namespace std;
class A
{

public:
    A();
    ~A();
    void myprintf();

    friend void youyuan();

private:
    int i;
};

void youyuan()
{
    cout << "you yuan" << endl;
    myprintf();
}
void A::myprintf()
{
    cout << "hello world" << endl;
}
int main()
{
    A a;
    youyuan();
    return 0;
}