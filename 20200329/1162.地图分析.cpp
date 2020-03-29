/*
 * File: 1162.地图分析.cpp
 * Project: 20200329
 * File Created: Sunday, 29th March 2020 10:58:10 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Sunday, 29th March 2020 10:58:12 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
 #include<queue>
 #include<vector>
 #include<iostream>
 using namespace std;

struct Node{
    int x;
    int y;
};

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int di[4] = {0, 0, 1, -1}; //设置上下左右4个方向
        int dj[4] = {1, -1, 0, 0};
        queue<vector<int>> land_que;
        int m = grid.size();
        int n = grid[0].size();
         // 先把所有的陆地都入队。
        vector<int> cache_point;
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (grid[i][j==1])
                {
                    cache_point.push_back(i);
                    cache_point.push_back(j);
                    land_que.push(cache_point);
                }
                cache_point.clear();
            }
        }
        bool hasOcean = false;
        vector<int> point;
        while(!land_que.empty())
        {
            point = land_que.front();
            land_que.pop();
            int x = point[0];
            int y = point[1];
            // 取出队列的元素，将其四周的海洋入队。
            for (int i=0;i<4;i++)
            {
                int newX = x + di[i];
                int newY = y + dj[i];
                if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] != 0) 
                {
                    continue;
                }
                grid[newX][newY] = grid[x][y] + 1; // 这里直接修改了原数组，因此就不需要额外的数组来标志是否访问
                hasOcean = true;
                vector<int> new_point={newX,newY};
                land_que.push(new_point);
            }
        }
        if (point.empty() || !hasOcean) 
        {
            return -1;
        }
        // 返回最后一次遍历到的海洋的距离。
        return grid[point[0]][point[1]] - 1;
    }
};