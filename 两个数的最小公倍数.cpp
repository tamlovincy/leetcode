/*
 * File: 两个数的最小公倍数.cpp
 * Project: LeetCode
 * File Created: Thursday, 12th March 2020 1:14:52 pm
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Thursday, 12th March 2020 1:14:57 pm
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */

/*
思路：
非递归形式：两个数相乘/这两个数的最大公约数
*/
#include <iostream>
#include <algorithm>
using namespace std;
// 最大公约数
int gcd_iter(int a, int b)
{
    int r;
    while(a%b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return b;
}
// 最大公约数
int gcd_recur(int a, int b)
{
    return b==0?a:gcd_recur(b,a%b);
}
// 最小公倍数
int lcm(int a, int b)
{
    return a*b/gcd_recur(a,b);
}

int main(void)
{   int a = 12345;
    int b = 125;
    cout <<a<<"和"<<b<<"的最大公约数为(非递归形式)："<<gcd_iter(a,b)<<endl;
    cout <<a<<"和"<<b<<"的最大公约数为(递归形式)："<<gcd_recur(a,b)<<endl;
    cout <<a<<"和"<<b<<"的最小公倍数为(非递归形式)："<<lcm(a,b)<<endl;
    return 0;
}