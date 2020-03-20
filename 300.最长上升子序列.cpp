/*
 * File: 300.最长上升子序列.cpp
 * Project: LeetCode
 * File Created: Saturday, 14th March 2020 11:23:36 am
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Saturday, 14th March 2020 11:24:25 am
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。
示例:
输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
*/
#include <iostream>
#include <vector>
using namespace std;

// 1.动态规划
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int max_size = 1;
        if (nums.size()==0) return 0;
        if (nums.size()==1) return 1;
        for (int i=0;i<nums.size();i++)
        {
            res[i] = 1;
            for (int j = 0; j<i;j++ )
            {
                if (nums[i]>nums[j])
                {
                    res[i]=max(res[i],res[j]+1);
                }
            }
            if (res[i]>max_size)
            {
                max_size=res[i];
                // cout << max_size << "," ;
            }
            // cout <<endl;
            cout <<res[i] <<" ";
        }
        return max_size;
    }
};

int main()
{
    vector<int> nums={10,9,2,5,3,7,101,18};
    Solution Slo;
    Slo.lengthOfLIS(nums);
}