/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-09-04 15:11:25
 * @LastEditTime: 2019-09-04 15:11:26
 * @LastEditors: Please set LastEditors
 */
#include <iostream>
template<typename T>   // 主模板
struct is_void : std::false_type
{
};
template<>  // 对 T = void 显式特化
struct is_void<void> : std::true_type
{
};
int main()
{
    // 对于任何非 void 的类型 T，该类均派生自 false_type
    std::cout << is_void<char>::value << '\n'; 
    // 但当 T 为 void 时类派生自 true_type
    std::cout << is_void<void>::value << '\n';
}