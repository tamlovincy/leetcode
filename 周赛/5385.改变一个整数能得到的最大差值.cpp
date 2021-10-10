/*
 * File: 5385.改变一个整数能得到的最大差值.cpp
 * Project: 周赛
 * File Created: Saturday, 2nd May 2020 11:02:26 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Saturday, 2nd May 2020 11:02:28 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给你一个整数 num 。你可以对它进行如下步骤恰好 两次 ：

选择一个数字 x (0 <= x <= 9).
选择另一个数字 y (0 <= y <= 9) 。数字 y 可以等于 x 。
将 num 中所有出现 x 的数位都用 y 替换。
得到的新的整数 不能 有前导 0 ，得到的新整数也 不能 是 0 。
令两次对 num 的操作得到的结果分别为 a 和 b 。

请你返回 a 和 b 的 最大差值 。

示例 1：

输入：num = 555
输出：888
解释：第一次选择 x = 5 且 y = 9 ，并把得到的新数字保存在 a 中。
第二次选择 x = 5 且 y = 1 ，并把得到的新数字保存在 b 中。
现在，我们有 a = 999 和 b = 111 ，最大差值为 888
示例 2：

输入：num = 9
输出：8
解释：第一次选择 x = 9 且 y = 9 ，并把得到的新数字保存在 a 中。
第二次选择 x = 9 且 y = 1 ，并把得到的新数字保存在 b 中。
现在，我们有 a = 9 和 b = 1 ，最大差值为 8
示例 3：

输入：num = 123456
输出：820000
*/

//思路：替换后x具有很大的值，y具有很小的值
#include <string>
#include <unordered_map>
class Solution {
public:
    int maxDiff(int num) {
        string num_s=to_string(num);
        string num_a=num_s;
        string num_b=num_s;
        int a=0;
        int b=0;
        int h_index=0;
        for (int i=0;i<num_s.size();i++)
        {
            if (num_s[i]!='9')
            {
                h_index=i;  //找到第一个不为9的索引
                break;
            }
        }
        if (!h_index) num_a=num_s;
        else
        {
            for (int i=h_index;i<num_a.size();i++)
            {
                if (num_a[i]==num_a[h_index]) num_a[i]='9';
            }
        }
        //b
        if (num_b[0]=='1') 
        {
            for (int i=1;i<num_b.size();i++)
            {
                if (num_b[i]==num_b[0]) num_b[i]='0';
            }
        }
        else if(num_b[0]!='1')
        {
            for (int i=0;i<num_b.size();i++)
            {
                if (num_b[i]==num_b[0]) num_b[i]='1';
            }
        }
        for (int i=0;i<num_s.size();i++)
        {
            a+=a * 10 + num_a[i] - '0';
            b+=b * 10 + num_b[i] - '0';
        }
        return b-a;
    }
};
