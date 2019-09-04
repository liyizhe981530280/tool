/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-08-30 17:14:33
 * @LastEditTime: 2019-08-30 18:34:51
 * @LastEditors: Please set LastEditors
 */
#include <iostream>
#include <typeinfo>
#include <list>
class animal
{
public:
    animal();
    ~animal();
    void virtual fly();
};
animal::animal(void)
{
}
animal::~animal(void)
{
}
void animal::fly()
{
    //std::cout << "wang wang -------" << std::end;
}

class bird : public animal
{
public:
    bird();
    ~bird();
    void fly();
};
class dog : public animal
{
public:
    dog();
    ~dog();
    void brak();
};
bird::bird()
{
}
bird::~bird()
{
}
void bird::fly(){
    std::cout << "i am is fly" << std::endl;
}
dog::dog()
{
}
dog::~dog()
{
}
void dog::brak()
{
    std::cout << "wang wang -------" << std::endl;
}

using namespace std;
int main()
{
    bird birdObject;
    dog dogObject;
    animal *pointBird = &birdObject;
    animal *pointd = &dogObject;

    list<animal *> mylist;
    mylist.push_back(pointd);
    mylist.push_back(pointBird);
    list<animal*>::iterator it;
    for(it = mylist.begin(); it != mylist.end(); ++it)
    {
       // cout << typeid(*it).name() << endl;
        animal *tmp = *it;
        if(typeid(*tmp) == typeid(bird))
        {
            cout << "hello world" << endl;
            tmp->fly();
        }else if(typeid(*tmp) == typeid(dog)){
            dog *i = dynamic_cast<dog *>(tmp);
            i->brak();
            //cout << "wangwang" << endl;
            //i->fly();
        }
    }
    #if 0
    if (typeid(*pointBird) == typeid(bird))
    {
        cout << "find bind" << endl;
    }
    else
    {
        cout << "connot change" << endl;
    }

    //bird *pointB = dynamic_cast<bird *>(pointBird);

   // pointB->fly();
   #endif 
    return 0;
}