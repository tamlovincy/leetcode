/*
 * File: 1277.统计全为 1 的正方形子矩阵.cpp
 * Project: 20200508
 * File Created: Tuesday, 12th May 2020 11:00:26 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Tuesday, 12th May 2020 11:00:35 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给你一个 m * n 的矩阵，矩阵中的元素不是 0 就是 1，请你统计并返回其中完全由 1 组成的 正方形 子矩阵的个数。
示例 1：

输入：matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
输出：15
解释： 
边长为 1 的正方形有 10 个。
边长为 2 的正方形有 4 个。
边长为 3 的正方形有 1 个。
正方形的总数 = 10 + 4 + 1 = 15.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones
*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.size()==0||matrix[0].size()==0) return 0;
        vector<vector<int>> dp(matrix.size(),vector<int> (matrix[0].size()));
        int res=0;
        for (int i=0;i<matrix.size();i++)
        {
            for (int j=0;j<matrix[0].size();j++)
            {
                if (matrix[i][j]==1)
                {
                    if (i==0||j==0) dp[i][j]=1;
                    else dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;  //状态转移方程
                }
                res+=dp[i][j];
            }
        }
        return res;
    }
};