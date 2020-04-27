/*
 * File: 33.搜索旋转排序数组.cpp
 * Project: 20200426
 * File Created: Monday, 27th April 2020 10:32:52 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Monday, 27th April 2020 10:32:56 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。
示例 1:
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
*/
#include <vector>
#include <iostream>
using namespace std;

//思路：怎么判断一个数组是有序的
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        if (nums.size()==1)
        {
            return nums[0]==target?0:-1;
        }
        int l=0;
        int r=nums.size()-1;
        int mid=0;
        while(l<=r)
        {
            mid=(r+l)/2;
            if (nums[mid] == target) return mid;
            if (nums[l]<=nums[mid])  //左半边有序
            {
                if (target>=nums[l]&&target<nums[mid])
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                } 
            }
            else //右半边有序
            {
                if (target>nums[mid]&&target<=nums[r])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                } 
            }
        }
        return -1;   
    }
};

int main()
{

    return 0;
}