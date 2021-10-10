/*
 * File: 1095.山脉数组中查找目标值.cpp
 * Project: 20200429
 * File Created: Wednesday, 29th April 2020 9:42:07 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Wednesday, 29th April 2020 9:42:18 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给你一个 山脉数组 mountainArr，请你返回能够使得 mountainArr.get(index) 等于 target 最小 的下标 index 值。

如果不存在这样的下标 index，就请返回 -1。

何为山脉数组？如果数组 A 是一个山脉数组的话，那它满足如下条件：

首先，A.length >= 3

其次，在 0 < i < A.length - 1 条件下，存在 i 使得：

A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]

你将 不能直接访问该山脉数组，必须通过 MountainArray 接口来获取数据：

MountainArray.get(k) - 会返回数组中索引为k 的元素（下标从 0 开始）
MountainArray.length() - 会返回该数组的长度

示例 1：

输入：array = [1,2,3,4,5,3,1], target = 3
输出：2
解释：3 在数组中出现了两次，下标分别为 2 和 5，我们返回最小的下标 2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-in-mountain-array
*/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 */
class MountainArray {
public:
    int get(int index);
    int length();
 };

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int l=0;
        int r=n-1;
        int mid=0;
        int peak=0;
        while(l<=r)
        {
            mid=(r+l)/2;
            if (mountainArr.get(mid)<mountainArr.get(mid+1)) //
            {
                r=mid+1;
            }
            else
            {
                r=mid;
            }
            
        }
    }
};