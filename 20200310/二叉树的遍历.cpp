/*
 * File: 二叉树的遍历.cpp
 * Project: LeetCode
 * File Created: Wednesday, 11th March 2020 1:54:54 pm
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Wednesday, 11th March 2020 1:55:01 pm
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */

/*
1. 二叉搜索树的中序遍历
左子树->根节点->右子树
非递归形式：使用栈来存储节点
. 首先一个指针p指向根节点
. 循环(当栈为空或指向的节点为空时结束循环)
    . 若p指向的节点不为空时
        . p入栈
        . p指向其左节点
    . 若p指向的节点为空时
        . 栈顶元素出栈
        . p指向其栈顶元素的右节点

2. 二叉搜索树的前序遍历
根节点->左子树->右子树
非递归形式：使用栈来存储节点
. 首先一个指针p指向根节点
. 循环(当栈为空时结束循环)
    . 将p指向栈顶元素
    . 弹出栈顶元素 (根节点)
    . 如果栈顶元素p的右子树存在
        . 将p的右子树压入栈中
    . 如果栈顶元素p的左子树存在
        . 将p的左子树压入栈中
*/
// 递归形式如下代码
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {} //构造函数与默认参数列表
};

//中序遍历递归形式
void InOrderTraverse_Recursion(TreeNode *root)
{
    if (root == nullptr)
        return;
    InOrderTraverse_Recursion(root->left);
    // doSomething(root);
    cout << root->val << ", ";
    InOrderTraverse_Recursion(root->right);
}

//中序遍历非递归形式
void InOrderTraverse_Iteration(TreeNode *root)
{
    stack<TreeNode *> st;
    TreeNode *p = root; //设置一个p指针指向根节点
    while (p != nullptr || !st.empty())
    {
        if (p)
        {
            st.push(p);
            p = p->left;
        }
        else
        {
            p = st.top(); //弹出栈顶节点赋值给p指针
            cout << p->val << ", ";
            st.pop();
            p = p->right;
        }
    }
    // return do something;
}
//前序遍历递归形式
void PreOrderTraverse_Recursion(TreeNode *root)
{
    if (root == nullptr)
        return;
        // doSomething(root);
    cout << root->val << ", ";
    PreOrderTraverse_Recursion(root->left);
    PreOrderTraverse_Recursion(root->right);
}
// 前序遍历非递归形式
void PreOrderTraverse_Iteration(TreeNode *root)
{
    stack<TreeNode *> st;
    TreeNode *p = root; //设置一个p指针指向根节点
    st.push(root);
    while(!st.empty())
    {
        p=st.top();
        cout <<p->val<< ", ";
        st.pop();
        if (p->right!=nullptr)
        {
            st.push(p->right);
        }
        if (p->left!=nullptr)
        {
            st.push(p->left);
        }
    }
}
//后序遍历递归形式
void PostOrderTraverse_Recursion(TreeNode *root)
{
    if (root == nullptr)
        return;
    PostOrderTraverse_Recursion(root->left);
    PostOrderTraverse_Recursion(root->right);
            // doSomething(root);
    cout << root->val << ", ";
}

// 后序遍历非递归形式
void PostOrderTraverse_Iteration(TreeNode *root)
{
    stack<TreeNode *> st;
    TreeNode* pre = nullptr; //用于记录右节点是否被访问过
    TreeNode *curr= root; //设置一个p指针指向根节点
    while(curr||!st.empty()) //当前节点为空或者栈为空退出循环
    {
        while(curr)//用于遍历左子树所有节点
        {
            st.push(curr);
            curr= curr->left;
        }
        curr=st.top(); //栈顶元素赋值给curr指针
        //若右节点已经访问过或者没有右节点  则输出该节点值
        if (curr->right==nullptr || pre==curr->right)
        {
            st.pop();
            cout << curr->val << ", ";
            pre = curr;
            curr = nullptr;
        }
        else
        {
            curr = curr->right;
            pre = nullptr;
        }
    }
}

int main()
{
    //建立二叉搜索树
    TreeNode *root;
    TreeNode Node_0(0);
    TreeNode Node_1(1);
    TreeNode Node_2(2);
    TreeNode Node_3(3);
    TreeNode Node_4(4);
    TreeNode Node_5(5);
    TreeNode Node_6(6);
    Node_4.left = &Node_2;
    Node_4.right = &Node_5;
    Node_2.left = &Node_1;
    Node_2.right = &Node_3;
    Node_5.right = &Node_6;
    Node_1.left = &Node_0;
    root = &Node_4; //根指针指向树的根节点
    cout << "中序遍历顺序(递归形式)：";
    InOrderTraverse_Recursion(root);
    cout << endl;
    cout << "中序遍历顺序(非递归形式)：";
    InOrderTraverse_Iteration(root);
    cout << endl;
    cout << "前序遍历顺序(递归形式)：";
    PreOrderTraverse_Recursion(root);
    cout << endl;
    cout << "前序遍历顺序(非递归形式)：";
    PreOrderTraverse_Iteration(root);
    cout << endl;
    cout << "后序遍历顺序(递归形式)：";
    PostOrderTraverse_Recursion(root);
    cout << endl;
    cout << "后序遍历顺序(非递归形式)：";
    PostOrderTraverse_Iteration(root);
    return 0;
}