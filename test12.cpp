/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-09-02 09:20:27
 * @LastEditTime: 2019-09-02 14:08:09
 * @LastEditors: Please set LastEditors
 */
#include <iostream>
using namespace std;
class A
{
public:
    A(){
     b = 0;
    };
    ~A(){

    };
    int getA()
    {
        cout << b << endl;
        return b;
    };
    int setA(int c)
    {
        b = c;
        cout << b << endl;
        return 0;
    };

private:
    int b;
};
class B : public A
{
public:
    int setB()
    {
        setA(15);
    };
    int getB()
    {
        getA();
    }
};
class C : public A
{
public:
    int getC()
    {
        getA();
        return 0;
    };
};

int main()
{
    B a;
    cout << "ddd" << a.setB() << endl;
    //cout << "ddd" << a.getB() << endl;
     C c;
     cout << "ccc" << c.getC() << endl;
    cout << "hello world" << endl;
    return 0;
}