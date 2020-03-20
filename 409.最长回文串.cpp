/*
 * File: 409.最长回文串.cpp
 * Project: LeetCode
 * File Created: Thursday, 19th March 2020 9:21:31 am
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Thursday, 19th March 2020 9:35:29 am
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
 /*
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
注意:
假设字符串的长度不会超过 1010。
示例 1:
输入:
"abccccdd"
输出:
7
解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> s_map(58); //建立哈希表映射字母
        int length=0;
        for (int i=0;i<s.size();i++)
        {
            s_map[s[i]-65]=s_map[s[i]-65]+1;  //将字母映射到哈希数组中
        }
        for (int j=0;j<s_map.size();j++)
        {
            if (s_map[j]>=2) //寻找数组中大于等于2的元素
            {
                if (s_map[j]%2==1) //奇数
                {
                    length+=s_map[j]-1;
                    s_map[j]=1; //将元素标记为1
                }
                else if (s_map[j]%2==0) //偶数
                {
                    length+=s_map[j];
                    s_map[j]=0; //将元素标记为0
                }
            }
        }
        for (int j=0;j<s_map.size();j++)
        {
            if (s_map[j]==1)
            {
                return length+1;
            }
        }
        return length;
    }
};

int main()
{
    string s="abcccacdd";
    Solution Slo;
    cout << "最长回文字符串长度为：" <<Slo.longestPalindrome(s);
}