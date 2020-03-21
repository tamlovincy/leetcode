/*
 * File: 面试题57-II.和为s的连续正数序列.cpp
 * Project: leetcode
 * File Created: Saturday, 21st March 2020 10:53:10 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Saturday, 21st March 2020 10:53:14 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
*/

//滑动窗口法
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> result; 
        int count = target/2+2;
        int sum=0;
        vector<int> window;
        for (int i=1;i<=count;)
        {
            if (sum<target)
            {
                window.push_back(i);
                sum+=i;
                i++;
            }
            else if(sum>target)
            {
                sum-=*window.begin();
                window.erase(window.begin());
            }
            else if (sum==target)
            {
                result.push_back(window);
                window.push_back(i);
                sum+=i;
                // window.clear();
                i++;
            }

        }
        return result;
    }
};