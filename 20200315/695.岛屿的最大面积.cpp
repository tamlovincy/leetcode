/*
 * File: 695.岛屿的最大面积.cpp
 * Project: LeetCode
 * File Created: Sunday, 15th March 2020 11:32:59 pm
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Sunday, 15th March 2020 11:33:07 pm
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。
你可以假设二维矩阵的四个边缘都被水包围着。
找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)
示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-area-of-island
*/
#include <iostream>
#include <vector>
using namespace std;

// 深度优先搜索
class Solution {
private:
    int dfs(vector<vector<int>>& grid, int cur_i, int cur_j) {
        if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) //处理边界和不为1的情况
            return 0;
        grid[cur_i][cur_j] = 0; //标记遍历过的格点
        int di[4] = {0, 0, 1, -1}; //设置上下左右4个方向
        int dj[4] = {1, -1, 0, 0};
        int ans = 1;
        for (int index = 0; index != 4; ++index) {
            int next_i = cur_i + di[index], next_j = cur_j + dj[index];
            ans += dfs(grid, next_i, next_j);
        }
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for (int i=0;i!=grid.size();i++)
        {
            for (int j=0;j!=grid[0].size();j++)
            {
                ans=max(ans,dfs(grid,i,j));
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    Solution Slo;
    cout <<"岛屿的最大面积为："<<Slo.maxAreaOfIsland(grid);
    return 0;
}