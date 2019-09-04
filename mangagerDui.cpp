/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-08-30 17:32:32
 * @LastEditTime: 2019-08-30 17:34:13
 * @LastEditors: Please set LastEditors
 */
#include  <iostream> 
#include  <typeinfo> 
using   namespace  std;

class  B{
public :
     virtual   void  fun(){}
};

class  D: public  B{
public :
     void  fun(){}
};

int  main()
{
    B  * p;
    D ob;
    p =& ob;
    cout << " typeid(*p).name()= " << typeid( * p).name() << endl;
     if (typeid( * p) == typeid(D))
        cout << " typeid(*p)==typeid(D) " << endl;
    cout << " typeid(p).name()= " << typeid(p).name() << endl;
     if (typeid(p) == typeid(B * ))
        cout << " typeid(p)==typeid(B*) " << endl;
    //ssystem( " pause " );
     return   0 ;
}
