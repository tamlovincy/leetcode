/*
 * @Author: Lingtan 
 * @Date: 2020-05-17 14:44:04 
 * @Last Modified by: Lingtan
 * @Last Modified time: 2020-05-17 14:44:30
 */
/*
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。

说明 :
    数组的长度为 [1, 20,000]。
    数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
*/
// class Solution {
// public:
//     int sum_array(vector<int>& nums, int l,int r)
//     {
//         int sum=0;
//         for (int i=l;i<=r;i++) sum+=nums[i];
//         return sum;
//     }
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         vector<int> cul(nums.size()+1,0);
//         int res=0;
//         int sum=0;
//         int l,r;
//         for (int i=1;i<=nums.size();i++){
//             cul[i]=cul[i-1]+nums[i-1];
//         }
//         for (l=0;l<cul.size();l++)
//         {
//             for (r=l+1;r<cul.size();r++)
//             {
//                 if (cul[r]-cul[l]==k) res++;
//             }
//         }
//         return res;

//     }
// };

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int res=0;
        int pre=0;
        map[0]=1;
        for (auto &num:nums)
        {
            pre+=num;
            if (map.find(pre-k)!=map.end()){
                res+=map[pre-k];
            }
            map[pre]++;
        }
        return res;
    }
};