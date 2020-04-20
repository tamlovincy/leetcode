/*
 * File: 200.岛屿数量.cpp
 * Project: 20200420
 * File Created: Monday, 20th April 2020 9:42:04 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Monday, 20th April 2020 9:42:08 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。

示例 1:

输入:
11110
11010
11000
00000
输出: 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;

class Solution_dfs {
private:
    static int dfs(vector<vector<char>>& grid,int cur_i,int cur_j)
    {
        if (cur_i<0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j]!='1') return 0;
        grid[cur_i][cur_j] = '0';//标记遍历过的的点
        int di[4] = {0, 0, 1, -1}; //设置上下左右4个方向
        int dj[4] = {1, -1, 0, 0};
        int ans=1;
        for (int index=0;index!=4;++index)
        {
            int next_i = cur_i+di[index];
            int next_j = cur_j+dj[index];
            ans+=dfs(grid,next_i,next_j);
        }
        return ans;
    }
public:
    static int numIslands(vector<vector<char>>& grid) {
        int res=0;
        for (int i=0;i!=grid.size();i++)
        {
            for (int j=0;j!=grid[0].size();j++)
            {
                if (grid[i][j]=='1')
                {
                    int ans = dfs(grid,i,j);
                    if (ans!=0) res++;
                }
            }
        }
        return res;
    }
};

class Solution_bfs {
public:
    static int numIslands(vector<vector<char>>& grid) {
        int res=0;
        int di[4] = {0, 0, 1, -1}; //设置上下左右4个方向
        int dj[4] = {1, -1, 0, 0};
        for (int i=0;i!=grid.size();i++)
        {
            for (int j=0;j!=grid[0].size();j++)
            {
                if (grid[i][j]=='1')
                {
                    res++;
                    grid[i][j]  ='0';
                    queue<pair<int,int>> que; //bfs
                    // stack<pair<int,int>> que;    //dfs
                    que.emplace(i,j);
                    while(!que.empty())  //bfs搜索每一个为'1'的节点
                    {
                        pair<int,int> p =que.front();  //bfs
                        // pair<int,int> p =que.top();       //dfs
                        int cur_i=p.first;
                        int cur_j=p.second;
                        que.pop();
                        for (int index=0;index!=4;++index)
                        {
                            int next_i=cur_i + di[index];
                            int next_j=cur_j + dj[index];
                            if (next_i>=0&&next_i<grid.size()&&next_j>=0&&next_j<grid[0].size()&&grid[next_i][next_j]=='1')
                            {
                                que.emplace(next_i,next_j);
                                grid[next_i][next_j]='0';
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<char>> grid,grid_;
    grid  = grid_= {{'1','1','0','0','1'},
                    {'1','1','0','0','0'},
                    {'0','0','1','0','0'},
                    {'0','0','0','1','1'},
                    {'1','1','0','1','1'}};
    cout << Solution_dfs::numIslands(grid) << endl;
    cout << Solution_bfs::numIslands(grid_) << endl;
    return 0;
}
