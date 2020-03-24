/*
一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

注意：本题相对原题稍作改动

示例 1：

输入： [1,2,3,1]
输出： 4
解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。
示例 2：

输入： [2,7,9,3,1]
输出： 12
解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。
示例 3：

输入： [2,1,4,5,3,1,1,3]
输出： 12
解释： 选择 1 号预约、 3 号预约、 5 号预约和 8 号预约，总时长 = 2 + 4 + 3 + 3 = 12。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-masseuse-lcci
*/

//定义动态规划dp数组
// (1) 以nums[i]结尾的前i个序列的最优值；(2) dp数组末尾表示前i个序列的最优值
#include<iostream>
#include<vector>
using namespace std;
//动态规划：此处定义dp数组末尾表示前i个序列的最优值
class Solution {
private:
    int max_value(int a, int b)
    {
        return a>b?a:b;
    }
public:
    int massage(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        if (nums.empty()) return dp[0];
        if (nums.size()==1) return nums[0];
        if (nums.size()==2) return max_value(nums[0],nums[1]);
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        for (int i = 2; i<nums.size();i++)
        {
            dp[i]=max_value(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};
int main()
{
    vector<int> nums={2,1,4,5,3,1,1,3};
    Solution Slo;
    cout << Slo.massage(nums);
    return 0;
}