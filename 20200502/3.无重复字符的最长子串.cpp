/*
 * File: 3.无重复字符的最长子串.cpp
 * Project: 20200502
 * File Created: Saturday, 2nd May 2020 3:25:31 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Saturday, 2nd May 2020 3:25:41 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int res=0;
        unordered_map<char,int> hash_map;
        for (int i=0,j=0;j<n;j++)
        {
            hash_map[s[j]]++;
            while(hash_map[s[j]]>1) hash_map[s[i++]]--;
            if (j-i+1>res) res=j-i+1;
        }
        return res;
    }
};

int main()
{
    string s="abcabcbb";
    cout << Solution::lengthOfLongestSubstring(s);
    return 0;
}