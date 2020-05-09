/*
 * File: 98.验证二叉搜索树.cpp
 * Project: 20200505
 * File Created: Tuesday, 5th May 2020 3:10:15 pm
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Tuesday, 5th May 2020 3:10:19 pm
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int *last =NULL; //定义一个指针用来记录
public:
    bool isValidBST(TreeNode* root) {
        if (root) 
        {
            if (!isValidBST(root->left)) return false;
            if (last && *last>=root->val) return false;
            last = &root->val;
            if (!isValidBST(root->right)) return false;
            return true;
        }
        else return true;
    }
};