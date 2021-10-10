/*
 * File: 463.岛屿的周长.cpp
 * Project: 20201030
 * File Created: Friday, 30th October 2020 12:44:15 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Friday, 30th October 2020 12:44:22 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    static int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> grid_pad(m+2,vector<int>(n+2,0));
        for (int i=1;i<m+1;i++){
            for (int j=1;j<n+1;j++){
                grid_pad[i][j] = grid[i-1][j-1];
            }
        }
        for (int i=0;i<grid_pad.size();i++){
            for (int j=0;j<grid_pad.size();j++){
                cout << grid_pad[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        int res = 0;
        for (int i = 1;i<m+1;i++){
            for(int j= 1;j<n+1;j++){
                if (grid_pad[i][j]==1){
                    if (grid_pad[i-1][j]==0) res++;
                    if (grid_pad[i][j-1]==0) res++;
                    if (grid_pad[i][j+1]==0) res++;
                    if (grid_pad[i+1][j]==0) res++;
                }
            }
        }
        return res;
    }
};

int main(){

    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout << Solution::islandPerimeter(grid) << endl;
    return 0;
}