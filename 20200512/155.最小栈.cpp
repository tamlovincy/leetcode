/*
 * File: 155.最小栈.cpp
 * Project: 20200512
 * File Created: Tuesday, 12th May 2020 8:49:42 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Tuesday, 12th May 2020 8:49:44 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。
 
示例:

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack
*/
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> MainSt;
    stack<int> SupSt;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        MainSt.push(x);
        if (SupSt.empty()||x<SupSt.top()) SupSt.push(x);
        else SupSt.push(SupSt.top());
    }
    
    void pop() {
        MainSt.pop();
        SupSt.pop();
    }
    
    int top() {
        return MainSt.top();
    }
    
    int getMin() {
        return SupSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */