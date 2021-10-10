/*
 * File: 129.求根到叶子节点数字之和.cpp
 * Project: 20201029
 * File Created: Thursday, 29th October 2020 10:58:50 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Thursday, 29th October 2020 10:59:47 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
#include<isotream>
#include<vector>
#include<string>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 核心思想：递归累乘
//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs (TreeNode* root,string s,vector<string> &res) {
        if (!root) return;
        s += to_string(root->val);
        if (!root->left && !root->right) res.push_back(s);
        else{
            dfs(root->left,s,res);
            dfs(root->right,s,res);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int res_sum=0;
        vector<string> res;
        string s;
        dfs(root,s,res);
        for (int i=0;i<res.size();i++){
            res_sum+=stoi(res[i]);
        }
        return res_sum;
    }
};

int main() {

    return 0;
}