/*
 * File: 53.最大子序和.cpp
 * Project: 20200503
 * File Created: Sunday, 3rd May 2020 9:22:28 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Sunday, 3rd May 2020 9:22:32 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int max_value(int a,int b)
    {
        return a>b?a:b;
    }
public:
    // int maxSubArray(vector<int>& nums) {
    //     // vector<int> dp(nums.size()-1,0);
    //     // dp[0] = nums[0];
    //     int max_sum = nums[0];
    //     for (int i = 1;i<nums.size();i++)
    //     {
    //         if (nums[i-1]>0)
    //         {
    //             nums[i]+=nums[i-1];
    //         }
    //         max_sum=max_value(max_sum,nums[i]);
    //     }
    //     return max_sum;
    // }
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        int max_sum=nums[0];
        for (int i = 1;i<nums.size();i++)
        {
            dp[i]=max_value(dp[i-1]+nums[i],nums[i]);
            max_sum=max_value(dp[i],max_sum);
        }
        return max_sum;
    }
};

int main()
{
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    Solution Slo;
    cout << Slo.maxSubArray(nums) << endl;
    return 0;
}