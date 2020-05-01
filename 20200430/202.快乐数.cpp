/*
 * File: 202.快乐数.cpp
 * Project: 20200430
 * File Created: Friday, 1st May 2020 4:53:09 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Friday, 1st May 2020 4:53:13 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果 可以变为  1，那么这个数就是快乐数。

如果 n 是快乐数就返回 True ；不是，则返回 False 。

示例：

输入：19
输出：true
解释：
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/happy-number
*/
//快慢指针
class Solution {
public:
    int squareSum(int n)
    {
        int sum=0;
        while(n>0)
        {
            int digit=n%10;
            sum+=digit*digit;
            n/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow=n;
        int fast=squareSum(n);
        while(slow!=fast)
        {
            slow=squareSum(slow);
            fast=squareSum(squareSum(fast));
        }      
        return slow==1;  
    }
};