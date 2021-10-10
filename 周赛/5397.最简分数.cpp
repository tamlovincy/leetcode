/*
 * @Author: Lingtan 
 * @Date: 2020-05-17 14:47:51 
 * @Last Modified by: Lingtan
 * @Last Modified time: 2020-05-17 14:49:51
 */
/*
给你一个整数 n ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于  n 的 最简 分数 。分数可以以 任意 顺序返回。
示例 1：

输入：n = 2
输出：["1/2"]
解释："1/2" 是唯一一个分母小于等于 2 的最简分数。

示例 2：

输入：n = 3
输出：["1/2","1/3","2/3"]

示例 3：

输入：n = 4
输出：["1/2","1/3","1/4","2/3","3/4"]
解释："2/4" 不是最简分数，因为它可以化简为 "1/2" 。

示例 4：

输入：n = 1
输出：[]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/simplified-fractions
*/
class Solution {
private: 
    int gcd(int a,int b)
    {
        return b==0?a:gcd(b,a%b);
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        if (n==1) return {};
        for (int i=1;i<n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                if (i!=1&&gcd(i,j)!=1) continue;
                string tmp=to_string(i)+'/'+to_string(j);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
