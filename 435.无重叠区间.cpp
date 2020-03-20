/*
 * File: 435.无重叠区间.cpp
 * Project: LeetCode
 * File Created: Monday, 16th March 2020 7:41:14 pm
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Monday, 16th March 2020 7:41:33 pm
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*

*/

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
using namespace std;

class Solution {
private:
    static bool compare(vector<int> a,vector<int> b)
    {
        return a[a.size()-1]<b[b.size()-1]; //按数组最后一个元素升序排列，如果改为return a>b，则为降序
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end(),compare);
        int count = 1;
        int x_end = intervals[0][1];
        for (vector<int> interv : intervals)
        {
            if (interv[0]>=x_end)
            {
                count++;
                x_end = interv[1];
            }
        }
        return intervals.size()-count;
    }
};

// bool compare(vector<int> a,vector<int> b)
// {
//   return a[a.size()-1]<b[b.size()-1]; //按数组最后一个元素升序排列，如果改为return a>b，则为降序
// }
int main()
{

    vector<vector<int>> intervals = {{1,9},{2,5},{3,4},{1,3}}; //[ [1,2], [2,3], [3,4], [1,3] ]
    Solution Slo;
    // sort(intervals.begin(),intervals.end(),compare);
    Slo.eraseOverlapIntervals(intervals);
    for (int i = 0; i < intervals.size(); i++)
    {
        for (int j = 0; j< intervals[0].size();j++)
        {
            cout<<intervals[i][j] << ", ";
        }
    }
    return 0;
}