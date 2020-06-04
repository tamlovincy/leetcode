/*
 * @Author: Lingtan 
 * @Date: 2020-05-27 09:06:35 
 * @Last Modified by: Lingtan
 * @Last Modified time: 2020-05-27 09:43:05
 */
/*
给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。

 

示例：

输入：A = [4,5,0,-2,-3,1], K = 5
输出：7
解释：
有 7 个子数组满足其元素之和可被 K = 5 整除：
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-sums-divisible-by-k
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// No_AC version
class Solution_no_ac {
private:
    static bool IsDivByK(int sum, int K)
    {
        return sum%K==0?true:false;
    }
public:
    static int subarraysDivByK(vector<int>& A, int K) {
        if (A.size()==1) return IsDivByK(A[0],K)==true?1:0;
        vector<int> cul(A.size()+1,0);
        cul[0]=A[0];
        int l=0;
        int r=0;
        int res=0;
        vector<int> res_v;
        for (int i=1;i<A.size();i++)
        {
            cul[i]=cul[i-1]+A[i]; //前缀和
            // cout << cul[i] << endl;
        }
        for (int l=0;l<cul.size();l++)
        {
            for (int r=l+1;r<cul.size();r++)
            {
                // cout << cul[r]-cul[l] << " ";
                if (IsDivByK(cul[r]-cul[l],K))
                {
                    // res_v.push_back(cul[r]-cul[l]);
                    // cout << cul[r]-cul[l] << endl;
                    res++;
                }
            }
            // cout << endl;
        }
        return res;
    }
};

class Solution {
private:
    static bool IsDivByK(int sum, int K)
    {
        return sum%K==0?true:false;
    }
public:
    static int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int,int> map;
        int res=0;
        int pre=0;
        map[0]=1;
        for (auto &num:A)
        {
            pre+=num;
            // cout << pre << endl;
            if (map.find(pre-K)!=map.end()){
                res+=map[pre-K];
            }
            map[pre]++;
        }
        return res;
    }
};

int main()
{
    vector<int> A={4,5,0,-2,-3,1};
    int K = 5;
    cout << Solution::subarraysDivByK(A,K) << endl;
    return 0;
}