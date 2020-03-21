/*
 * File: 面试题_16_07_最大数值_不用比较运算符.cpp
 * Project: LeetCode
 * File Created: Thursday, 12th March 2020 2:03:43 pm
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Thursday, 12th March 2020 2:03:46 pm
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
编写一个方法，找出两个数字a和b中最大的那一个。不得使用if-else或其他比较运算符。

示例：
输入： a = 1, b = 2
输出： 2
*/
/* 位运算：C/C++语言中逻辑右移和算数右移共享同一个运算符>>。
编译器决定使用逻辑右移还是算数右移，根据的是运算数的类型。
如果运算数类型是unsigned则采用逻辑右移，而signed则采用算数右移。
对于signed类型的数据，如果需要使用算数右移，或者unsigned类型的数据需要使用逻辑右移，都需要进行类型转换。
类型	绝对值位运算
int8_t	(var ^ (var >> 7)) - (var >> 7)
int16_t	(var ^ (var >> 15)) - (var >> 15)
int32_t	(var ^ (var >> 31)) - (var >> 31)
int64_t	(var ^ (var >> 63)) - (var >> 63)
正数补码等于它的原码
补码：原码取反+1(符号位不变)

作者：dexin
链接：https://leetcode-cn.com/problems/maximum-lcci/solution/ji-yu-wei-yun-suan-shi-xian-da-xiao-bi-jiao-by-dex/
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int maximum(int a, int b) {
        int64_t res = (int64_t)a-(int64_t)b;
        int64_t abs_res = (res ^ (res >> 63)) - (res >> 63);
        return (int)((int64_t)a+(int64_t)b+abs_res)/2;
    }
};

int swap(int a, int b);

int main(void)
{
    uint8_t b = 126;
    int8_t a = 126;
    int16_t c = 120;
    // a = a<<31;
    // a = a>>31;
    cout << a << " " << b << " " <<c<<endl;
    int x = -999;
    int y = -258;
    Solution Slo;
    cout << x<<"和"<<y<<"的最大值为："<<Slo.maximum(x,y)<<endl;
    swap(x,y);
    cout << x<<"和"<<y<<"交换了为："<<x<<"和"<<y<<endl;
    return 0;
}

/*
位运算拓展：交换a和b的值，不能另外开辟内存，采用异或运算
int swap(int a, int b)
*/
void swap(int &a, int &b)
{
    a = a^b;
    b = a^b;
    a = a^b;
}
