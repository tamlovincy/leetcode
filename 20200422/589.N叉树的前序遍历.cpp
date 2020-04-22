/*
 * File: 589.N叉树的前序遍历.cpp
 * Project: 20200422
 * File Created: Wednesday, 22nd April 2020 2:05:47 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Wednesday, 22nd April 2020 2:05:52 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一个 N 叉树，返回其节点值的前序遍历和后序遍历。

例如，给定一个 3叉树 :
          1           
       /  |  \
      3   2   4      
     / \   
    5  6   
返回其前序遍历: [1,3,5,6,2,4].
返回其后序遍历: [5,6,3,2,4,1].
*/
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
//前序遍历
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};
        stack<Node*> st;
        vector<int> res;
        st.push(root);
        while(!st.empty())
        {
            int size = st.size();
            Node* node = st.top();
            st.pop();
            res.push_back(node->val);
            for (auto rIter = node->children.rbegin();rIter!=node->children.rend();rIter++) //逆序迭代器
            {
                st.push(*rIter);
            }
        }
        return res;
    }
//后序遍历
public:
    void postorder(Node* root,vector<int> &res)
    {
        if (!root) return;
        for (auto node : root->children)
        {
            postorder(node,res);
        }
        res.push_back(root->val);
        return;
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorder(root,res);
        return res;
    }

};