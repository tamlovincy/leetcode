/*
 * File: 55.跳跃游戏.cpp
 * Project: 20200417
 * File Created: Friday, 17th April 2020 10:09:59 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Friday, 17th April 2020 10:10:04 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums[0]==0&&nums.size()>1) return false;
        if (nums[0]==0&&nums.size()==1) return true;
        queue<int> qq; //放置元素为0的索引
        for (int i = 1;i<nums.size();i++)
        {
            if (nums[i]==0) qq.push(i);
        }
        vector<bool> res(nums.size(),false); //对0位置的地方标记是否能到达
        while(!qq.empty())
        {
            int tmp = qq.front();  // [3,2,1,0,4] tmp = 3
            qq.pop();
            for (int i = 0; i<tmp;i++)
            {
                if (nums[i]>tmp-i)  //计算当前元素的值是否大于该元素位置到0元素位置的距离
                {
                    res[tmp]=true;
                    break;
                }
            }
        }
        for (int i = 1;i<nums.size();i++)
        {
            if (nums[i]==0&&!res[i]&&i!=nums.size()-1) return false;//0的位置处为false，如果res[i]==false，i为最后一个位置，则也通过
        }
        return true;
    }
};