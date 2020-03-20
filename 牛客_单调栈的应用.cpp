/*
 * File: 牛客_单调栈的应用.cpp
 * Project: LeetCode
 * File Created: Tuesday, 17th March 2020 3:02:51 pm
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Tuesday, 17th March 2020 3:17:54 pm
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
单调栈中存放的数据应该是有序的，所以单调栈也分为单调递增栈和单调递减栈
(1) 单调递增栈：数据出栈的序列为单调递增序列
(2) 单调递减栈：数据出栈的序列为单调递减序列
模拟实现一个递增单调栈：
stack<int> st;
//此处一般需要给数组最后添加结束标志符，具体下面例题会有详细讲解
for (遍历这个数组)
{
	if (栈空 || 栈顶元素大于等于当前比较元素)
	{
		入栈;
	}
	else
	{
		while (栈不为空 && 栈顶元素小于当前元素)
		{
			栈顶元素出栈;
			更新结果;
		}
		当前数据入栈;
	}
}

*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> a, b;
stack<int> st1, st2;
  
int main() {
    // int n, x[100001];
    // cin >> n;
    // int ans = 0;
    // for (int i = 0; i < n; i++) cin >> x[i];
    int n = 6;
    int x[6] = {5, 3, 8, 3, 2, 5};
    for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--) 
    {
        a.push_back(st1.size());// []
        // cout << st1.size()<< " ";
        b.push_back(st2.size());
        // cout << st2.size()<< " ";
        while (!st1.empty() && st1.top() <= x[i]) 
        {
            st1.pop(); //实现单调递增栈[,5]
        }
        while (!st2.empty() && st2.top() <= x[j]) 
        {
            st2.pop(); //实现单调递增栈[,5]
        }
        st1.push(x[i]); //将st1.top()>x[i]的数据压入栈
        st2.push(x[j]);
    }
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; i++) cout << b[i] + a[i] + 1<< " ";
    cout <<endl;
    while(!st1.empty())
    {
        cout << st1.top()<<" ";
        st1.pop();
    }
    return 0;
}
