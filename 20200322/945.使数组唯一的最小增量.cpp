/*
 * File: 945.使数组唯一的最小增量.cpp
 * Project: 20200322
 * File Created: Sunday, 22nd March 2020 1:54:09 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Sunday, 22nd March 2020 1:54:13 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
 /*
 给定整数数组 A，每次 move 操作将会选择任意 A[i]，并将其递增 1。
 返回使 A 中的每个值都是唯一的最少操作次数。
 示例 1:

 输入：[1,2,2]
 输出：1
 解释：经过一次 move 操作，数组将变为 [1, 2, 3]。
 示例 2:

 输入：[3,2,1,2,1,7]
 输出：6
 解释：经过 6 次 move 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
 可以看出 5 次或 5 次以下的 move 操作是不能让数组的每个值唯一的。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique

 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.empty()) return 0;
        int res = 0;
        sort(A.begin(), A.end());
        for (int i = 0; i<A.size()-1;i++)
        {
            if (A[i]<A[i+1])
            {
                continue;
            }
            else //A[i]  >= A[i+1]
            {
                res += A[i]-A[i+1]+1;
                A[i+1]+=A[i]-A[i+1]+1;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> A = {3,2,1,2,1,7};
    Solution Slo;
    cout << "最少操作次数为：" << Slo.minIncrementForUnique(A) ;
    return 0;
}