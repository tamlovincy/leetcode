/*
 * File: 1248.统计优美子数组.cpp
 * Project: 20200421
 * File Created: Tuesday, 21st April 2020 9:34:48 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Tuesday, 21st April 2020 9:34:54 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给你一个整数数组 nums 和一个整数 k。
如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。
请返回这个数组中「优美子数组」的数目。
示例 1：

输入：nums = [1,1,2,1,1], k = 3
输出：2
解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
示例 2：

输入：nums = [2,4,6], k = 1
输出：0
解释：数列中不包含任何奇数，所以不存在优美子数组。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-number-of-nice-subarrays
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt = 0;
        int res = 0;
        int odd_num[nums.size()+2];
        for (int i= 0;i<nums.size();i++)
        {
            if (nums[i]%2==1) odd_num[++cnt]=i;
        }
        odd_num[0] = -1;
        odd_num[++cnt] = nums.size();
        for (int i =1;i+k<=cnt;i++)
        {
            res+=(odd_num[i]-odd_num[i-1])*(odd_num[i+k]-odd_num[i+k-1]);
        }
        return res;
    }
};

class Solution_ {
public:
    static int numberOfSubarrays(vector<int>& nums, int k) {
        // 奇数为1, 偶数为0, 子区间和为k的种类数
        int len = nums.size();
        for (int i=0; i<len; i++) {
            if (nums[i] & 1) nums[i] = 1;
            else nums[i] = 0;
        }
        unordered_map<long long, int> mp{{0,1}};
        long long sum = 0;
        int res = 0;
        for (int i=1; i<=len; i++) {
            sum += nums[i-1];
            // cout << sum << endl;
            // sum - k = x
            res += mp[sum - k];
            // cout << res << endl;
            mp[sum] ++;
        }
        return res;
    }
};

int main()
{
    vector <int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;
    cout << Solution_::numberOfSubarrays(nums,k) << endl;
    return 0;
}