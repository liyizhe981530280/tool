/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-08-30 16:28:10
 * @LastEditTime: 2019-08-30 16:30:29
 * @LastEditors: Please set LastEditors
 */
#include <istream>
struct Day
{
    explicit Day(int d) : val(d)
    {
       
    }
     int val;
};

struct Month
{
    explicit Month(int m) : val(m)
    {
        
    }
    int val;
};

struct Year
{
    explicit Year(int y) : val(y)
    {
        
    }
    int val;
};

class Date
{
public:
    Date(const Month &m, const Day &d, const Year &y);
};
Date::Date(const Month &m,const Day &d, const Year &y)
{
    
}
int main()
{
    Date d(Month(3), Day(30), Year(1995));
    return 0;
}