/*
 * File: 365.水壶问题.cpp
 * Project: LeetCode
 * File Created: Saturday, 21st March 2020 10:19:12 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Saturday, 21st March 2020 10:19:14 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？
如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。
你允许：
装满任意一个水壶
清空任意一个水壶
从一个水壶向另外一个水壶倒水，直到装满或者倒空
示例 1: (From the famous "Die Hard" example)

输入: x = 3, y = 5, z = 4
输出: True
示例 2:

输入: x = 2, y = 6, z = 5
输出: False
*/
class Solution {
private:
    int gcd_iter(int a, int b)
    {
        if (a==0) return b;
        if (b==0) return a;
        int r;
        while(a%b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        return b;
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z==0) return true;
        if (x==0&&y==0&&z!=0) return false;
        if (x+y<z) return false;
        if (z%gcd_iter(x,y)==0) return true;
        return false;
    }
};
