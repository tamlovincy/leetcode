/*
 * File: fibo_array.cpp
 * Project: 2021
 * File Created: Wednesday, 25th August 2021 11:27:07 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Wednesday, 25th August 2021 11:29:42 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2021 Your Company, <<xjtu>>
 */
/*
斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。
该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给你 n ，请计算 F(n) 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fibonacci-number
*/
#include <iostream>
#include <vector>
using namespace std;

int fibo(int n){
    vector<int> dp(n+1,0);
    if (n==0) return 0;
    if (n==1) return 1;
    dp[0] = 0;
    dp[1] = 1;
    for (int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    // cout << "testing!\n";
    cout << fibo(4) << endl;

}