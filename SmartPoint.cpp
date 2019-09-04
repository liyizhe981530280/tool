#include <iostream>
#include <memory>
#include <string>
using namespace std;
template <typename Object>
class SmartPointer
{
  public:
    // constructor
    SmartPointer(Object *p = nullptr) : m_ptr(p), m_pRefCnt(new size_t{})
    {
        if (p)
            *m_pRefCnt = 1;
        else
            *m_pRefCnt = 0;
    }
    //~constructor
    ~SmartPointer()
    {
        releaseCount();
    }
    // copy constructor
    SmartPointer(const SmartPointer &rhs)
    {
        if (this != &rhs)
        {
            m_ptr = rhs.m_ptr;
            m_pRefCnt = rhs.m_pRefCnt;
            (*m_pRefCnt)++;
        }
    }
    // move constructor
    SmartPointer(const SmartPointer &&rhs) : m_ptr{std::move<rhs.m_ptr>},
                                             m_pRefCnt(rhs.m_pRefCnt)
    {
        rhs.m_ptr = nullptr;
        rhs.m_pRefCnt = nullptr;
    }

    //assignment operator for copy
    SmartPointer &operator=(const SmartPointer &rhs)
    {
        if (this != &rhs)
        {
            releaseCount();
            m_ptr = rhs.m_ptr;
            m_pRefCnt = rhs.m_pRefCnt;
            (*m_pRefCnt)++;
        }

        return *this;
    }
    //assigment operator for move

    SmartPointer &operator=(SmartPointer &&rhs)
    {
        std::swap(m_ptr, rhs.m_ptr);
        std::swap(m_pRefCnt, rhs.m_pRefCnt);

        return *this;
    }

    Object &operator*() const
    {
        return *m_ptr;
    }

    Object *operator->() const
    {
        return &this->operator*();
    }

  private:
    void releaseCount()
    {
        if (m_pRefCnt)
        {
            (*m_pRefCnt)--;
            cout << "Descrease release count. Current Count " << (*m_pRefCnt);
            if (*m_pRefCnt == 0)
            {
                delete m_ptr;
                delete m_pRefCnt;
                cout << "Free head resource ,Release count = 0" << endl;
            }
        }
    }

  private:
    Object *m_ptr;
    size_t *m_pRefCnt;
}

int main(int argc, char const *argv[])
{
    
    SmartPointer<int> i {new int{10}};
    SmartPointer<int> j {new int{15}};
    i = std::move(j);
    cout << *i << endl;
    cout << *j << endl;
    return 0;
}
