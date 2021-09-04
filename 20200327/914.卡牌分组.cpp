/*
 * File: 914.卡牌分组.cpp
 * Project: 20200327
 * File Created: Friday, 27th March 2020 12:07:24 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Friday, 27th March 2020 12:10:42 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一副牌，每张牌上都写着一个整数。
此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：
每组都有 X 张牌。
组内所有的牌上都写着相同的整数。
仅当你可选的 X >= 2 时返回 true。
示例 1：

输入：[1,2,3,4,4,3,2,1]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
示例 2：

输入：[1,1,1,2,2,2,3,3]
输出：false
解释：没有满足要求的分组。
示例 3：

输入：[1]
输出：false
解释：没有满足要求的分组。
示例 4：

输入：[1,1]
输出：true
解释：可行的分组是 [1,1]
示例 5：

输入：[1,1,2,2,2,2]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[2,2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards
*/
// gcd(a,b,c)=gcd(gcd(a,b),c)
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
private:
    int gcd(int a, int b)  
    {
        int r;
        while(a%b!=0)
        {
            r = a%b;
            a = b;
            b = r;
        }
        return b;
    }
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.empty()||deck.size()==1) return false;
        unordered_map<int,int> res;
        unordered_map<int,int>::iterator iter;
        for (int i :deck) //填入哈希表
        {
            res[i]++;
        }
        if (res.size()==1)
        {
            return true;
        }
        int gcd_val=res.begin()->second;
        iter=res.begin();
        iter++;
        while (iter!=res.end())
        {
            gcd_val=gcd(gcd_val,iter->second);
            if (gcd_val==1) return false;
            iter++;
        }
        if (gcd_val==1) return false;
        return true;
    }
};

int main()
{
    Solution Slo;
    vector<int> deck = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,4,4,5,5,5,5,6,6,7,7,8,8};
    cout << Slo.hasGroupsSizeX(deck)<<endl;
    return 0;
}