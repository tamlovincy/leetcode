/*
 * File: 225.用队列实现栈.cpp
 * Project: 20200323
 * File Created: Monday, 23rd March 2020 10:40:59 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Monday, 23rd March 2020 10:41:03 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
注意:

你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-stack-using-queues
*/
#include<queue>
#include<iostream>
using namespace std;

class MyStack {
private:
    queue<int> Myque_1;
    queue<int> Myque_2;
    int top_val;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }  //构造函数
    
    /** Push element x onto stack. */
    void push(int x) {
        Myque_1.push(x);
        top_val = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */ //pop_front
    int pop() { 
        if (Myque_1.empty())
        {
            return 0;
        }
        while(Myque_1.size()>1)
        {
            top_val = Myque_1.front();
            Myque_2.push(top_val);
            Myque_1.pop();
        }
        int value = Myque_1.front();
        Myque_1.pop();
        queue<int> tmp = Myque_1;
        Myque_1 = Myque_2;
        Myque_2 = tmp;
        return value;
    }
    
    /** Get the top element. */
    int top() {
        if (Myque_1.empty())
        {
            return 0;
        }
        return top_val;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return Myque_1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main()
{
    MyStack* mySta = new MyStack();
    cout << "push顺序：";
    for (int i = 0; i<5;i++)
    {
        mySta->push(i);
        cout <<i << ",";
    }
    cout << endl;
    cout << "当前栈top element：" <<mySta->top() << endl;
    cout << "当前栈是否为空：" <<mySta->empty() << endl;
    cout << "pop顺序：";
    for (int i = 0; i<4;i++)
    {
        cout << mySta->pop()<<" ";
    }
    cout << endl;
    cout << "当前栈top element：" <<mySta->top() << endl;
    mySta->pop();
    cout << "当前栈是否为空：" <<mySta->empty() << endl;
}