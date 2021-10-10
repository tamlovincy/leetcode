/*
 * @Author: Lingtan 
 * @Date: 2020-05-21 09:26:56 
 * @Last Modified by: Lingtan
 * @Last Modified time: 2020-05-21 09:45:35
 */
/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
*/
/*
动态规划解法：
设p[i,j]表示从字符S的i到j子串
状态转移方程：p[i,j]=p[i+1,j-1]^(Si==Sj)
边界条件：p[i,i]==true
         p[i,i+1]=(Si==Si+1)
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n));
        
        
    }
};