/*
 * File: 912.排序数组.cpp
 * Project: 20200331
 * File Created: Tuesday, 31st March 2020 8:56:37 am
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Tuesday, 31st March 2020 8:56:45 am
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一个整数数组 nums，将该数组升序排列。

示例 1：

输入：[5,2,3,1]
输出：[1,2,3,5]
示例 2：

输入：[5,1,1,2,0,0]
输出：[0,0,1,1,2,5]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-an-array
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
    struct cmp{
        bool operator()(int a,int b)
        {
            return a>b;
        }
    };

private:
    vector<int> MinHeap_sort(vector<int> &nums)
    {
        vector<int> res;
        priority_queue<int,vector<int>,cmp> MinHeap;
        for (int i=0;i<nums.size();i++)
        {
            MinHeap.push(nums[i]);
        }
        for (int i=0;i<nums.size();i++)
        {
            res.push_back(MinHeap.top());
            MinHeap.pop();
        }
        return res;
    }

private:
    int partition(vector<int>& nums,int low,int high){ //返回主元的位置
        int pivot = nums[low]; //选主元
        while(low<high) {
            while(low<high && nums[high]>=pivot)
            {
                --high;
            }
            nums[low] = nums[high];
            while(low<high && nums[low]<=pivot) 
            {
                ++low;
            }
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;   
    }
    void QuickSort(vector<int>& nums,int low,int high)
    {
        if (low<high)
        {
            int pivotpos = partition(nums,low,high);
            QuickSort(nums,low,pivotpos-1);
            QuickSort(nums,pivotpos+1,high);
        }
        return;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        // vector<int> res = MinHeap_sort(nums);
        // return res;
        QuickSort(nums,0,nums.size()-1);
        return nums;
    }
};

// class Solution {
// private:
//     void swap(int &a,int &b)
//     {
//         a=a^b;
//         b=a^b;
//         a=a^b;
//     }
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         for (int i=0;i<nums.size();i++)
//         {
//             for (int j=0;j<nums.size();j++)
//             {
//                 if (nums[i]<nums[j])
//                 {
//                     swap(nums[i],nums[j]);
//                 }
//             }
//         }
//         return nums;
//     }
// };

int main()
{
    vector<int> nums= {5,1,1,2,0,0};
    Solution Slo;
    vector<int> res=Slo.sortArray(nums);
    for (int i=0;i<res.size();i++)
    {
        cout << res[i]<<" ";
    }
    return 0;
}