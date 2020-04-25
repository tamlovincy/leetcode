/*
 * File: 784.字母大小写全排列.cpp
 * Project: 20200425
 * File Created: Saturday, 25th April 2020 11:07:51 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Saturday, 25th April 2020 11:07:54 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。

示例:
输入: S = "a1b2"
输出: ["a1b2", "a1B2", "A1b2", "A1B2"]

输入: S = "3z4"
输出: ["3z4", "3Z4"]

输入: S = "12345"
输出: ["12345"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-case-permutation
*/
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    void backtrack(string S,vector<string> &res,string path)
    {
        if (path.length()==S.length())
        {
            res.push_back(path);
            return;
        }
        for (int i=0;i<S.length();i++)
        {
            if (path.find(S[i])!=string::npos) //当前路径在path中
            {
                if (int(S[i])>=65)
                {
                    path.push_back(S[i]^0Xff);
                }
                else continue;
            }   
        }
    }

public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        string path;


    }
};