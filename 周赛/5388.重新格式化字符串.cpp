/*
 * File: 5388.重新格式化字符串.cpp
 * Project: 周赛
 * File Created: Sunday, 19th April 2020 10:55:30 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Sunday, 19th April 2020 10:55:34 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给你一个混合了数字和字母的字符串 s，其中的字母均为小写英文字母。
请你将该字符串重新格式化，使得任意两个相邻字符的类型都不同。
也就是说，字母后面应该跟着数字，而数字后面应该跟着字母。
请你返回 重新格式化后 的字符串；如果无法按要求重新格式化，则返回一个 空字符串 
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reformat(string s) {
        string res;
        string str;
        string num;
        for (auto i :s)
        {
            if (int(i)>=97) str.push_back(i);
            else num.push_back(i);
        }
        if (str.size()-num.size()==1) 
        {
            for (int i =0;i<num.size();i++)
            {
                res.push_back(str[i]);
                res.push_back(num[i]);
            }
            res.push_back(str.back());
            return res;
        }
        if (num.size()-str.size()==1)
        {
            for (int i =0;i<str.size();i++)
            {
                res.push_back(num[i]);
                res.push_back(str[i]);
            }
            res.push_back(num.back());
            return res;
        }
        if (num.size()-str.size()==0)
        {
            for (int i =0;i<str.size();i++)
            {
                res.push_back(str[i]);
                res.push_back(num[i]);
            }
            return res;
        }
        return res;
    }
};

int main()
{
    return 0;
}