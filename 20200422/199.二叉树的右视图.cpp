/*
 * File: 199.二叉树的右视图.cpp
 * Project: 20200422
 * File Created: Wednesday, 22nd April 2020 9:54:18 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Wednesday, 22nd April 2020 9:54:24 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
示例:
输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-right-side-view
*/
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    static vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        if (root->left==NULL && root->right==NULL)
        {
            res.push_back(root->val);
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            res.push_back(que.front()->val);
            int size = que.size(); //
            while(size--)
            {
                TreeNode* Node = que.front();
                que.pop();
                if (Node->right) que.push(Node->right);
                if (Node->left) que.push(Node->left);
            }
        }
        return res;
    }
};

class Solution_dfs {
public:
    vecotor<int> res;
public:
    static void dfs(TreeNode *root,int depth)
    {
        if (!root) return;
        if (depth==res.size()) res.push_back(root->val);
        dfs(root->right,depth+1);
        dfs(root->left,depth+1);
        return;
    }
public:
    static vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        return res;
    }
};
