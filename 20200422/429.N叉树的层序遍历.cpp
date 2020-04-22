/*
 * File: 429.N叉树的层序遍历.cpp
 * Project: 20200422
 * File Created: Wednesday, 22nd April 2020 1:14:46 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Wednesday, 22nd April 2020 1:14:49 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。

例如，给定一个 3叉树 :
          1           
       /  |  \
      3   2   4      
     / \   
    5  6         
返回其层序遍历:
[
     [1],
     [3,2,4],
     [5,6]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal
*/
// Definition for a Node.
#include <stack>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
//层序遍历
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        queue<Node*> que;
        vector<vector<int>> res;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            vector<int> tmp;
            for (int i=0;i<size;i++)
            {
                Node* node = que.front();
                que.pop();
                tmp.push_back(node->val);
                for (auto NodeTmp : node->children)
                {
                    que.push(NodeTmp);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
