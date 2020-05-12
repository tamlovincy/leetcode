/*
 * File: 221.最大正方形.cpp
 * Project: 20200508
 * File Created: Tuesday, 12th May 2020 9:38:15 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Tuesday, 12th May 2020 9:38:17 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-square
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size()==0||matrix[0].size()==0) return 0;
        vector<vector<int>> dp(matrix.size(),vector<int> matrix[0].size());
        int res=0;
        for (int i=0;i<matrix.size();i++)
        {
            for (int j=0;j<matrix[0].size();j++)
            {
                if (matrix[i][j]=='1')
                {
                    if (i==0||j==0) dp[i][j]=1;
                    else dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                }
                res=max(res,dp[i][j]);
            }
        }
        return res*res;
    }
};