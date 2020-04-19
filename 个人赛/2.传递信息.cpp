/*
 * File: 2.传递信息.cpp
 * Project: 个人赛
 * File Created: Saturday, 18th April 2020 3:11:36 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Saturday, 18th April 2020 4:28:42 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    void dfs(int root,int cur,int depth,int n, int k,int &res,vector<vector<int>> &G)
    {
        for (auto v:G[cur])
        {
            if (v==n-1&&depth==k)
            {
                res++;
            }
            if (depth<k)
            {
                dfs(root,v,depth+1,n,k,res,G);
            }
        }
        return;
    }
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> G(n);
        int res=0;
        for (auto tmp :relation)
        {
            G[tmp[0]].push_back(tmp[1]);  
        }
        dfs(0,0,1,n,k,res,G);
        return res;
    }
};

int main()
{   
    Solution Slo;
    int n=5;
    int k=3;
    vector<vector<int>> relation = {{0,2},{2,1},{3,4},{2,3},{1,4},{2,0},{0,4}};
    cout << Slo.numWays(n,relation,k) << endl;
    return 0;
}