/*
 * File: 56.合并区间.cpp
 * Project: 20200416
 * File Created: Thursday, 16th April 2020 9:39:59 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Thursday, 16th April 2020 9:40:42 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给出一个区间的集合，请合并所有重叠的区间。

示例 1:
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool static compare (vector<int> a,vector<int> b)
    {
        return a[1]<b[1];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return intervals;
        sort (intervals.begin(),intervals.end(),compare);
        vector<vector<int>> res;
        vector <int> v_back = intervals[intervals.size()-1];
        for (int i =intervals.size()-2;i<intervals.size();i--)
        {
            vector<int> v_front = intervals[i];
            if (v_back[0]<=v_front[1]) //处理重叠
            {
                v_back[0] = min(v_front[0],v_back[0]);
                continue;
            }
            else //处理不重叠
            {
                res.push_back(v_back);
                v_back = v_front;
            }  
        }
        res.push_back(v_back);
        return res;
    }
};

int main()
{

    vector<vector<int>> intervals = {{2,3},{4,5},{6,7},{8,9},{1,10}};
    vector<vector<int>> res;
    Solution Slo;
    res = Slo.merge(intervals);
    for (auto interv : res)
    {
        for (auto i : interv)
        {
            cout << i << ", ";
        }
    }
    return 0;
}