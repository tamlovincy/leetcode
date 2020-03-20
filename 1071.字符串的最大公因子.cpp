/*
 * File: 1071.字符串的最大公因子.cpp
 * Project: LeetCode
 * File Created: Thursday, 12th March 2020 11:00:54 am
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Thursday, 12th March 2020 11:01:34 am
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */

/*
对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。

返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/greatest-common-divisor-of-strings
*/
/*
求解最大公因数
辗转相除法：
while(a%b!=0)
{
    r=a%b;
    a=b; //a变为b的值
    b=r; //b变为余数的值
    r=a%b; //再求余数直至r=0时取b的值
}
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int gcd(int a,int b)
    {
        return b==0?a:gcd(b,a%b);
    }
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1+str2!=str2+str1) return "";
        return str1.substr(0,gcd(str1.size(),str2.size()));
    }
};

//最大公因数递归求法
int gcd_recur(int a,int b)
{
    return b==0?a:gcd_recur(b,a%b);
}
//最大公因数非递归求法
int gcd_iter(int a, int b)  
{
    int r;
    while(a%b!=0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return b;
}

int main()
{
    string str1="ABCABC";
    string str2="ABC";
    string str=str1+str2;
    string sstr=str.substr(0,5);

    Solution Slo;
    string result = Slo.gcdOfStrings(str1,str2);
    for (int i = 0; i<result.size();i++)
    {
        cout<<result[i];
    }
    // cout<< Slo.gcd(5,10);
    cout << endl;
    cout<< gcd_iter(5,10);
    return 0;
    
}