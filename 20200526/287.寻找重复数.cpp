/*
 * @Author: Lingtan 
 * @Date: 2020-05-26 17:54:53 
 * @Last Modified by: Lingtan
 * @Last Modified time: 2020-05-26 17:55:40
 */
/*
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

示例 1:

输入: [1,3,4,2,2]
输出: 2
示例 2:

输入: [3,1,3,4,2]
输出: 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-duplicate-number
*/
// Floyd 判圈算法
// 垃圾hash算法
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> hash(nums.size()+1,0);
        int res=0;
        for (int i=0;i<nums.size();i++)
        {
            hash[nums[i]]++;
            if (hash[nums[i]]>1)
            {
                res=nums[i];
                break;
            }
        }
        return res;
    }
};

// Floyd 判圈算法