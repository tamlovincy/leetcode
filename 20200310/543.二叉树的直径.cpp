/*
 * File: 543.二叉树的直径.cpp
 * Project: LeetCode
 * File Created: Tuesday, 10th March 2020 10:34:11 am
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Wednesday, 11th March 2020 9:22:55 am
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    int max = 0;
    int Max(int a, int b)
    {
        return a > b ? a : b;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return max;
    }

private:
    int dfs(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftHeight = dfs(root->left);   //递归左子树深度
        int rightHeight = dfs(root->right); //递归右子树深度
        max = Max(leftHeight + rightHeight, max);
        return Max(leftHeight, rightHeight) + 1;
    }
};