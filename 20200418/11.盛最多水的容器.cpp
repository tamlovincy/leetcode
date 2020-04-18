/*
 * File: 11.盛最多水的容器.cpp
 * Project: 20200418
 * File Created: Saturday, 18th April 2020 10:43:16 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Saturday, 18th April 2020 10:43:28 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX(x, y)   ((x) > (y) ? (x) : (y))
#define MIN(x, y)   ((x) < (y) ? (x) : (y))
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int first = 0;
        int end = height.size()-1;
        while(first<end)
        {
            int tmp = min(height[first],height[end])*(end-first);
            res = max(res,tmp);
            if (height[first]>height[end]) end--;
            else first++;
        }
        return res;
    }
};

int main()
{
    vector<int> height = {2,3,4,5,18,17,6};//{1,8,6,2,5,4,8,3,7};
    Solution Slo;
    cout << Slo.maxArea(height) << endl;

    return 0;
}