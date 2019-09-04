/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-08-30 11:00:55
 * @LastEditTime: 2019-08-30 11:04:25
 * @LastEditors: Please set LastEditors
 */
#include <iostream>
using namespace std;

class Cat
{
public:
    void setWeight(int w) { weight = w; } //设置重量
    int print() { return weight; }        //返回重量的大小
    int length;

private:
    int weight;
};

template <typename T>
inline int mymax(const T &a,const T &b)
{
    return a > b ? a :b;
}
int main()
{
    Cat cat;
    cat.length = 5;
    //cat.setWeight(5);//设置cat的重量为5
    cout << "The cat's weight is " << cat.print() << endl;
    cout << "the reslult" << mymax(1,2);
    return 0;
}
