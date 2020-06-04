/*
 * @Author: Lingtan 
 * @Date: 2020-05-29 09:59:48 
 * @Last Modified by: Lingtan
 * @Last Modified time: 2020-05-29 10:04:31
 */
/*
你是一个专业的小偷，计划偷窃沿街的房屋。
每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房
屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，
一夜之内能够偷窃到的最高金额。
示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    static int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+3,0); //以i结尾的
        int res=0;
        for (int i=0;i<nums.size();i++)
        {
            dp[i+3]=max(dp[i+3-2]+nums[i],dp[i+3-3]+nums[i]);
            res=max(res,dp[i+3]);
        }
        return res;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+6,0); //以i结尾的
        if (n==0) return 0;
        if (n==1) return nums[0];
        if (n==2) return max(nums[0],nums[1]);
        if (n==3) return nums[1];


    }
};

int main()
{
    vector<int> nums={2,7,9,3,1}; //{2,1,1,2}
    cout << Solution::rob(nums) << endl;
    return 0;
}