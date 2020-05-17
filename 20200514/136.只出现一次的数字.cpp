/*
 * @Author: Lingtan 
 * @Date: 2020-05-17 14:42:29 
 * @Last Modified by: Lingtan
 * @Last Modified time: 2020-05-17 14:42:56
 */
/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1

示例 2:

输入: [4,1,2,1,2]
输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number
*/

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int,int> hash_map;
//         int res=0;
//         for (int i=0;i<nums.size();i++)
//         {
//             hash_map[nums[i]]++;
//         }
//         for (auto iter=hash_map.begin();iter!=hash_map.end();iter++)
//         {
//             if (iter->second==1){
//                 res= iter->first;
//                 break;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for (auto num:nums){
            res=res^num;
        }
        return res;
    }
};