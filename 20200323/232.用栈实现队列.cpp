/*
 * File: 232.用栈实现队列.cpp
 * Project: 20200323
 * File Created: Monday, 23rd March 2020 11:53:21 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Monday, 23rd March 2020 11:53:30 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
 /*
 使用栈实现队列的下列操作：
push(x) -- 将一个元素放入队列的尾部。
pop() -- 从队列首部移除元素。
peek() -- 返回队列首部的元素。
empty() -- 返回队列是否为空。
示例:
MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false
说明:

你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-queue-using-stacks
 */

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> MyStack_1;
    stack<int> MyStack_2;
    int back_val;
    int front_val;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    /** Push element x to the back of queue. */
    void push(int x) {
        if (MyStack_1.empty())
        {
            front_val=x;
        }
        MyStack_1.push(x);
    }
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (MyStack_2.empty())
        {
            while(!MyStack_1.empty())
            {
                MyStack_2.push(MyStack_1.top());
                MyStack_1.pop();
            }
        }
        int value = MyStack_2.top();
        MyStack_2.pop();
        return value;
    }
    
    /** Get the front element. */
    int peek() {
        if (!MyStack_2.empty()) 
        {
            return MyStack_2.top();
        }
        return front_val;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return MyStack_1.empty() && MyStack_2.empty();
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyQueue* myQue = new MyQueue();
    cout << "push顺序：";
    for (int i = 0; i<5;i++)
    {
        myQue->push(i);
        cout <<i << ",";
    }
    cout << endl;
    cout << "当前队列front element：" <<myQue->peek() << endl;
    cout << "当前队列是否为空：" <<myQue->empty() << endl;
    cout << "pop顺序：";
    for (int i = 0; i<4;i++)
    {
        cout << myQue->pop()<<" ";
    }
    cout << endl;
    cout << "当前队列front element：" <<myQue->peek() << endl;
    myQue->pop();
    cout << "当前队列是否为空：" <<myQue->empty() << endl;
    // int param_2 = myQue->pop();
    // int param_3 = myQue->peek();
    // bool param_4 = myQue->empty();
    // cout <<param_2<<","<<param_3<<","<<param_4<<endl;
    return 0;
}