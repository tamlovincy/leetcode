/*
 * File: 232.用栈实现队列.cpp
 * Project: 20200323
 * File Created: Monday, 23rd March 2020 11:53:21 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Monday, 23rd March 2020 11:53:30 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
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