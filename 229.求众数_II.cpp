/*
 * File: 229.求众数 II.cpp
 * Project: LeetCode
 * File Created: Friday, 13th March 2020 11:39:09 am
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Friday, 13th March 2020 11:39:12 am
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。
示例 1:
输入: [3,2,3]
输出: [3]
示例 2:
输入: [1,1,1,3,3,2,2,2]
输出: [1,2]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element-ii
*/
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;
// hash_map法，不能达到O(1)的空间复杂度
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> nums_hash;
        unordered_map<int,int>::iterator iter;
        vector<int> result;
        for (int i:nums)
        {
            nums_hash[i]=nums_hash[i]+1;
        }
        for (iter = nums_hash.begin();iter!=nums_hash.end();iter++)
        {
            if (iter->second>nums.size()/3)
            {
                result.push_back(iter->first);
            }
        }
        return result;  
    }
};
// 摩尔投票法
/*
如果至多选一个代表，那他的票数至少要超过一半（⌊ 1/2 ⌋）的票数；
如果至多选两个代表，那他们的票数至少要超过⌊ 1/3 ⌋的票数；
如果至多选m个代表，那他们的票数至少要超过⌊ 1/(m+1) ⌋的票数。
所以以后碰到这样的问题，而且要求达到线性的时间复杂度以及常量级的空间复杂度，直接套上摩尔投票法。
作者：wotxdx
链接：https://leetcode-cn.com/problems/majority-element-ii/solution/liang-fu-dong-hua-yan-shi-mo-er-tou-piao-fa-zui-zh/
*/
class Solution_Moore_vote {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate_1=nums[0];
        int candidate_2=nums[0];
        int count_1=0;
        int count_2=0;
        vector<int> result;
        if (nums.size()==0)
        {
            return result;
        }
        for (int num : nums)
        {
            //投票
            if (candidate_1==num)
            {
                count_1++;
                continue; //满足条件直接进行下一票
            }
            if (candidate_2==num)
            {
                count_2++;
                continue;
            }
            //第1个候选人配对
            if (count_1==0) //抵消票没有了，换候选人
            {
                candidate_1=num;
                count_1++;//换候选人后给这个候选人一张抵消票
                continue;
            }
            // 第二个候选人配对
            if (count_2==0)
            {
                candidate_2=num;
                count_2++;
                continue;
            }  
            count_1--; //均不相同时，抵消票
            count_2--; //均不相同时，抵消票
        }
        // 计数阶段
        // 找到了两个候选人之后，需要确定票数是否满足大于 N/3
        count_1 = 0;
        count_2 = 0;
        for (int num : nums)
        {
            if (candidate_1==num)
            {
                count_1++;
            }
            else if (candidate_2==num)
            {
                count_2++;
            }
        }
        if (count_1>nums.size()/3)
        {
            result.push_back(candidate_1);
        }
        if (count_2>nums.size()/3)
        {
            result.push_back(candidate_2);
        }
        return result;
    }
};

int main()
{
    vector<int> result_1;
    vector<int> nums={1,1,1,2,3,4,5};
    Solution Slo;
    result_1=Slo.majorityElement(nums);
    cout << "所求众数为(hash_map法)：";
    for (int i =0;i<result_1.size();i++)
    {
        cout << result_1[i] << ","; 
    }
    cout << endl;

    vector<int> result_2;
    Solution_Moore_vote Slo_Morgan;
    result_2=Slo_Morgan.majorityElement(nums);
        cout << "所求众数为(摩尔投票法)：";
    for (int i =0;i<result_2.size();i++)
    {
        cout << result_2[i] << ","; 
    }
    cout << endl;
    return 0;
}