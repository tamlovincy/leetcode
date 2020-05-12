/*
 * File: 50.Pow(x, n).cpp
 * Project: 20200511
 * File Created: Tuesday, 12th May 2020 8:47:23 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Tuesday, 12th May 2020 8:48:13 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/powx-n
*/

class Solution {
public:
    double myPow(double x, int n) {
        double res=1.0;
        for (int i=n;i!=0;i/=2)
        {
            if (i%2!=0)
            {
                res*=x;
            }
            x*=x;
        }
        return n>0?res:1/res;
    }
};