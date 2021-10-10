/*
 * @Author: Lingtan 
 * @Date: 2020-05-18 22:14:49 
 * @Last Modified by: Lingtan
 * @Last Modified time: 2020-05-18 23:40:17
 */
/*
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-subarray
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static int maxProduct_(vector<int>& nums) {
        vector<int> maxF(nums.size(),0);
        vector<int> minF(nums.size(),0);
        maxF[0]=minF[0]=nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            maxF[i] = max(maxF[i-1]*nums[i],max(minF[i-1]*nums[i],nums[i]));
            minF[i] = min(maxF[i-1]*nums[i],min(minF[i-1]*nums[i],nums[i]));
        }
        // return *max_element(maxF.begin(), maxF.end());
        int res=maxF[0];
        for (int i = 0; i < nums.size(); i++)
        {
            res=max(res,maxF[i]);
        }
        return res;  
    }
    static int maxProduct(vector<int>& nums) {
        int maxf=nums[0];
        int minf=nums[0];
        int res=nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            maxf=max(maxf*nums[i],max(minf*nums[i],nums[i]));
            minf=min(maxf*nums[i],min(minf*nums[i],nums[i]));
            res=max(maxf,res);
        }
        return res;  
    }
};


int main()
{
    vector<int> nums={2,3,-2,4};
    cout << Solution::maxProduct(nums)<< endl;

    return 0;
}
