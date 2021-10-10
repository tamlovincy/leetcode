/*
 * @Author: Lingtan 
 * @Date: 2020-06-04 10:14:43 
 * @Last Modified by: Lingtan
 * @Last Modified time: 2020-06-04 10:52:09
 */
/*
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]

提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。

说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/product-of-array-except-self
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        if (n==0 || n==1) return {};
        vector<int> res(n,0);
        vector<int> prefix(n+2,1);
        vector<int> suffix(n+2,1);
        prefix[0+1]=nums[0];  //前缀积
        suffix[n-1+1]=nums[n-1]; //后缀积
        for (int i=1;i<n;i++)
        {
            prefix[i+1]=prefix[i-1+1]*nums[i];
        }
        for (int i=n-2;i>=0;i--)
        {
            suffix[i+1]=suffix[i+1+1]*nums[i];
        }
        for (int i=0;i<n;i++)
        {
            res[i]=prefix[i-1+1]*suffix[i+1+1];
        }
        return res;
    }
};