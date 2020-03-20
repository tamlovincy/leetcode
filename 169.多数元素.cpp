/*
 * File: 169.多数元素.cpp
 * Project: LeetCode
 * File Created: Friday, 13th March 2020 10:37:28 am
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Friday, 13th March 2020 10:37:32 am
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
示例 1:
输入: [3,2,3]
输出: 3
示例 2:
输入: [2,2,1,1,1,2,2]
输出: 2
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
*/
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;
//unordered_map<int,int>  res key value  可用res[key]进行索引
class Solution {
// private:    
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> res;//哈希表
        int count;
        int max_element=0;
        for (int i:nums)  //语法类似于python的for i in nums
        {
            res[i]+=1; 
            if (res[i]>max_element)
            {
                max_element=res[i];
                count = i;
            }
        }
        return count;
    }
};
int main()
{
    unordered_map<int,int> res;
    vector<int> nums={2,2,1,1,2,2,2,-1,-1,-1,-1,-1,-1};
    Solution Slo;
    cout <<Slo.majorityElement(nums) <<endl;
    return 0;
}