/*
 * File: 69.x的平方根.cpp
 * Project: 20200509
 * File Created: Saturday, 9th May 2020 10:18:04 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Saturday, 9th May 2020 10:18:12 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sqrtx
*/
//二分法
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int mid=0;
        int ans = -1;
        while(left<=right)
        {
            mid = (left+right)/2;
            if ((long long)mid*mid<=x) 
            {
                ans=mid;
                left=mid+1;
            }
            else if ((long long)mid*mid>x) right=mid-1; 
        }
        return ans;
    }
};

//牛顿迭代法