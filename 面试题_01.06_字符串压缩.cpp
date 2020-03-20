/*
 * File: 面试题_01.06_字符串压缩.cpp
 * Project: LeetCode
 * File Created: Monday, 16th March 2020 11:10:44 am
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Monday, 16th March 2020 11:10:47 am
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。
比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。
你可以假设字符串中只包含大小写英文字母（a至z）。

示例1:
 输入："aabcccccaaa"
 输出："a2b1c5a3"

示例2:
 输入："abbccd"
 输出："abbccd"
 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/compress-string-lcci
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//ASCII 48:0 49:1
class Solution {
public:
    string compressString(string S) {
        string str;
        if (S.size()==0||S.size()==1) return S;
        str.push_back(S[0]);
        int count = 1;
        for (int i=1;i<S.size();i++)
        {
            if (S[i]==S[i-1])
            {
                count++;
                if (i==S.size()-1)
                {
                    str+=to_string(count); //处理最后一段字符串是连续相同字符的情况
                }
            }
            else
            {
                str+=to_string(count);
                str.push_back(S[i]);
                count = 1;  
            }
        }
        if (S[S.size()-1]!=S[S.size()-2])
        {
            str+=to_string(count); //处理最后一个字符是单字符的情况
        }
        if (str.size()>=S.size())
        {
            return S;
        }
        else
        {
            return str;
        }
    }
};

int main()
{
    string str = "QSWEEEEEEeeeeeiiiiiiiiiiijjjjjjjjjjjjjjjjjjjjjjjjjfafaiiifappppppnN";
    string str_2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcdef";
    string result;
    Solution Slo;
    result = Slo.compressString(str_2);
    cout << "字符串压缩结果：";
    for (int i = 0; i<result.size();i++)
    {
        cout << result[i];
    }
    cout << endl;
    return 0;
}