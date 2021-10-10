/*
 * File: 4.切分数组.cpp
 * Project: 战队赛
 * File Created: Saturday, 25th April 2020 5:20:56 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Saturday, 25th April 2020 6:20:34 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
[2,3,3,2,3,3]分割成[2,3,3,2]和[3,3]共2种
[2,3,5,7]分割成[2],[3],[5],[7]共4种
对数组进行分割使其子数组的首和尾元素的最大公约数大于1，求最小分割次数
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static int gcd_(int a,int b)
    {
        return b==0?a:gcd_(b,a%b);
    }
public:
    static int splitArray(vector<int>& nums) {
        int res=0;
        int length=nums.size();
        if (gcd_(nums[0],nums.back())>1) return 1;
        int i=0;
        while(i<length-1)
        {
            vector<int> cache;
            for (int j=i+1;j<length;j++)
            {
                if (gcd_(nums[j],nums[i])>1)
                    cache.push_back(j);
                else cache.push_back(i+1);
            }
            i=cache.back();
            res++;
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {2,3,5,7};    //{2,3,3,2,3,3};
    sort(nums.rbegin(),nums.rend());
    for (int i=0;i<nums.size();i++)
    {
        cout << nums[i] << " ";
    }
    // cout << Solution::splitArray(nums) << endl;
    return 0;
}