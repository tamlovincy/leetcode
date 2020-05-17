/*
 * @Author: Lingtan 
 * @Date: 2020-05-17 14:38:25 
 * @Last Modified by: Lingtan
 * @Last Modified time: 2020-05-17 14:41:07
 */
/*
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int length=que.size();
            vector<int> sub_res;
            for (int i=0;i<length;i++)
            {
                TreeNode* tmp = que.front();
                que.pop();
                sub_res.push_back(tmp->val);
                if (tmp->left) que.push(tmp->left);
                if (tmp->right) que.push(tmp->right);
            }
            res.push_back(sub_res);
        }
        return res;
    }
};
