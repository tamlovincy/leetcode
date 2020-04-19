/*
 * File: 4.最小跳跃次数.cpp
 * Project: 个人赛
 * File Created: Saturday, 18th April 2020 4:30:56 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Saturday, 18th April 2020 4:36:59 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int minJump(vector<int>& jump) {
        vector<bool> visit(jump.size(),true);
        int cur = 0; //用于记录索引
        int next = 0;  
        int res=0; 
        if (jump.size()==1) return res;
        while(next<jump.size())
        {
            visit[cur] = false;
            next = jump[cur];
            res++;
            int tmp = 0;
            for (int j=1; j<next;j++)
            {
                if (visit[j])
                {
                    tmp = max(tmp,jump[j]+j);
                }
                visit[j] = false;
            }
            if (jump[next]+next>=tmp)
            {
                cur = next;
                next = jump[next]+next;
                res++;
            }
            else
            {
                cur = next;
                next = tmp;
                res++;
            }
        }
        return res+1;
    }
};

class Solution {
public:
    int minJump(vector<int>& jump) {
        int n = jump.size();
        vector<int> d(2 * n + 1, 10000000);
        deque<int> q;
        q.push_back(0);
        d[0] = 0;
        while(not q.empty())
        {
            int u = q.front();
            q.pop_front();
            if(u == 2 * n) break;
            if(u < n){
                if(u + jump[u] >= n)
                {
                    if(d[2 * n] > d[u] + 1)
                    {
                        d[2 * n] = d[u] + 1;
                        q.push_back(2 * n);
                    }
                }
                else if(d[u + jump[u]] > d[u] + 1)
                {
                    d[u + jump[u]] = d[u] + 1;
                    q.push_back(u + jump[u]);
                }
                if(d[u + n] > d[u] + 1)
                {
                    d[u + n] = d[u] + 1;
                    q.push_back(u + n);
                }
            }
            if(u >= n)
            {
                if(d[u - n] > d[u])
                {
                    d[u - n] = d[u];
                    q.push_front(u - n);
                }
                if(u > n and d[u - 1] > d[u])
                {
                    d[u - 1] = d[u];
                    q.push_front(u - 1);
                }
            }
        }
        return d.back();
    }
};

int main()
{
    vector<int> jump = {2, 1, 1, 1, 1, 1};
    Solution Slo;
    cout << Slo.minJump(jump) << endl;

    return 0;
}