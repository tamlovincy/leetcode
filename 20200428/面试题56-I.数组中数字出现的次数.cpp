/*
 * File: 面试题56-I.数组中数字出现的次数.cpp
 * Project: 20200428
 * File Created: Tuesday, 28th April 2020 9:21:38 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Tuesday, 28th April 2020 9:22:09 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

示例 1：

输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
示例 2：

输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> hash_table;
        for(int i=0;i<nums.size();i++)
        {
            hash_table[nums[i]]++;
        }
        for(auto iter=hash_table.begin();iter!=hash_table.end();iter++)
        {
            if (iter->second!=2) res.push_back(iter->first);
        }
        return res;
    }
};

