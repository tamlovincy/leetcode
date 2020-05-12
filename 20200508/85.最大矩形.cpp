/*
 * File: 85.最大矩形.cpp
 * Project: 20200508
 * File Created: Tuesday, 12th May 2020 2:04:06 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Tuesday, 12th May 2020 2:04:10 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

示例:

输入:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-rectangle
*/
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size()==0) return 0;
        int maxArea = 0;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size()));
        for (int i=0;i<matrix.size();i++)
        {
            for (int j=0;j<matrix[0].size();j++)
            {
                if (matrix[i][j]=='1') 
                {
                    dp[i][j]=j==0?1:dp[i][j-1]+1;
                    int width = dp[i][j];
                    for (int k=i;k>=0;k--)
                    {
                        width=min(width,dp[k][j]);
                        maxArea=max(maxArea,width*(i-k+1));
                    }
                }
            }
        }
        return maxArea;
    }
};