/*
 * File: tribo_array.cpp
 * Project: 2021
 * File Created: Wednesday, 25th August 2021 11:57:49 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Wednesday, 25th August 2021 11:57:52 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2021 Your Company, <<xjtu>>
 */
/*
泰波那契序列 Tn 定义如下： 
T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2
给你整数 n，请返回第 n 个泰波那契数 Tn 的值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-th-tribonacci-number
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        if (n<=2) return dp[n];
        for (int i=3;i<=n;i++){
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
};


int main(){

    Solution Slo;
    cout << Slo.tribonacci(25) << endl;
    return 0;
}