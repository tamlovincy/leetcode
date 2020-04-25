/*
 * File: 46.全排列.cpp
 * Project: 20200425
 * File Created: Saturday, 25th April 2020 9:43:52 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Saturday, 25th April 2020 9:43:57 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    static void backtrack (int n, vector<int>& nums, vector<vector<int>>& res, int first)
    {
        if(first==n) res.push_back(nums);
        for (int i = first;i<n;i++)
        {
            swap(nums[first],nums[i]);
            backtrack(n,nums,res,first+1);
            swap(nums[first],nums[i]);
        }
    }
    static vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums.size(),nums,res,0);  
        return res;
    }
};

class Solution_ {
public:
    static void dfs (vector<int>& nums,vector<vector<int>>& res,vector<int> &path)
    {
        if (path.size()==nums.size())
        {
            res.push_back(path);
            return;
        }
        for (int i=0;i<nums.size();i++)
        {
            if (find(path.begin(),path.end(),nums[i])!=path.end()) continue; //当前选择已在路径中，则跳过
            path.push_back(nums[i]);//做选择
            dfs(nums,res,path);//递归
            path.pop_back(); //撤销选择
        }
    }
    static vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums,res,path);  
        return res;
    }
};


int main()
{
    vector<int> nums={1,2,3};
    vector<vector<int>> res;

    res = Solution::permute(nums);
    for (int i =0;i<res.size();i++)
    {
        for (int j=0;j<res[0].size();j++)
        {
            cout << res[i][j] << "," ;
        }
        cout << endl;
    }

    return 0;
}