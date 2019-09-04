//为多态基类声明virtual析构函数
#include <iostream>
#include <string>
 #include<cstddef>
using namespace std;
enum TimerType
{
    Atomic,
    Wator,
    Wrist
};

class TimeKeeper
{
  public:
    ~TimeKeeper()
    {
        cout << "TimeKeeper::~TimeKeeper()" << endl;
    }
};

class AtomicClock : public TimeKeeper
{
  public:
    ~AtomicClock() { cout << "AtomicClock::~AtomicClock()" << endl; }
};

TimeKeeper *getTimeKeeper(TimerType type)
{
    TimeKeeper *tk;
    switch (type)
    {
    case Atomic:
        tk = new AtomicClock;
        break;
    case Wator:
        //tk = new WatorClock;
        break;
    case Wrist:
       // tk = new WristWatch;
        break;
    default:
        tk = nullptr;
        break;
    }
    return tk;
}

int main(int argc, char const *argv[])
{

    TimeKeeper *tk = getTimeKeeper(Atomic);
    delete tk;
    // TimerKeeper::TimerKeeper()
    // 如果析构函数不是virtual的，可见不会调用子类的析构函数
    // 如果将基类的析构函数声明为virtual，
    // 当derived class对象经由base class指针删除时，就会先调用基类的析构函数，再调用父类的析构函数
    return 0;
}
