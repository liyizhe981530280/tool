#include <iostream>
#include <ctype.h>
#include <locale>
#include <iterator>
#include <cmath>
#include <string>
#include <vector>
#include <initializer_list>
#include <ctime>

using namespace std;

const string &shorterString(const string &s1, const string &s2){
    return (s1.size() <= s2.size()) ? s1:s2;
}

string &shorterString(string &s1, string &s2){
    auto &r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
    return const_cast<string &>(r);
}


int main(int argc, char const *argv[])
{
    
    string str1 = "123", str2 = "456";
    string &strRef = shorterString(str1, str2);
     cout << strRef << endl;

     const char *cp = "890";
     string str = static_cast<string> (cp);
     cout << str <<endl;
    return 0;
}
