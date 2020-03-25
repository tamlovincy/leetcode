/*
 * File: 892.三维形体的表面积.cpp
 * Project: 20200325
 * File Created: Wednesday, 25th March 2020 9:43:08 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Wednesday, 25th March 2020 9:43:13 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。
每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。
请你返回最终形体的表面积。

示例 1：

输入：[[2]]
输出：10
示例 2：

输入：[[1,2],[3,4]]
输出：34
示例 3：

输入：[[1,0],[0,2]]
输出：16

示例 4：

输入：[[1,1,1],[1,0,1],[1,1,1]]
输出：32
示例 5：

输入：[[2,2,2],[2,1,2],[2,2,2]]
输出：46
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surface-area-of-3d-shapes
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        if (grid.size()==1)
        {
            if (grid[0][0]==0) return 0;
            return 4*grid[0][0]+2;
        }
        int sum = 0;
        for (int i=0;i<grid.size();i++)
        {
            for (int j=0;j<grid.size();j++)
            {
                if (grid[i][j]==0)
                {
                    sum += 0;  //该点为0不满足表面积表达式
                }
                else
                {
                    sum += 4*grid[i][j]+2;
                }
                if (j<grid.size()-1)
                {
                    if (grid[i][j]<=grid[i][j+1])
                    {
                        sum-=2*grid[i][j];
                    }
                    else if (grid[i][j]>grid[i][j+1])
                    {
                        sum-=2*grid[i][j+1];
                    }
                }
                if (i<grid.size()-1)
                {
                    if (grid[i][j]<=grid[i+1][j])
                    {
                        sum-=2*grid[i][j];
                    }
                    else if (grid[i][j]>grid[i+1][j])
                    {
                        sum-=2*grid[i+1][j];
                    }
                }
            }
        }
        return sum;
    }
};
int main()
{
    // int n =5;
    // vector<vector<int>> m(n,vector<int>(n)); //定义矩阵
    // for (int i =0;i<n;i++)
    // {
    //     for (int j=0;j<n;j++)
    //     {
    //         m[i][j] = i+j;
    //         cout << m[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<vector<int>> grid = {{2,2,2},{2,1,2},{2,2,2}};
    Solution Slo;
    cout << "三维形体的表面积为：" << Slo.surfaceArea(grid);
    return 0;
}