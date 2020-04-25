/*
 * File: 面试题08.11.硬币.cpp
 * Project: 20200423
 * File Created: Thursday, 23rd April 2020 11:39:55 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Thursday, 23rd April 2020 11:40:00 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)

示例1:

 输入: n = 5
 输出：2
 解释: 有两种方式可以凑成总金额:
5=5
5=1+1+1+1+1
示例2:

 输入: n = 10
 输出：4
 解释: 有四种方式可以凑成总金额:
10=10
10=5+5
10=5+1+1+1+1+1
10=1+1+1+1+1+1+1+1+1+1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-lcci
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int waysToChange(int n) {
        int coins[] = {1,5,10,25};
        vector<int> dp(n+1,1);
        for (int i=1;i<4;i++)
        {
            int coin=coins[i];
            if (coin>n) return dp[n];
            for (int j=coin;j<dp.size();j++)
            {
                dp[j]=(dp[j]+dp[j-coin])%1000000007;
            }
        }
        return dp[n];
    }
};

int main()
{
    cout << Solution::waysToChange(25)<< endl;
    return 0;
}