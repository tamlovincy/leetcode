#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        if (nums.size()==1) return nums;
        vector<int> res;
        int sum=0;
        int sum_subarray=0;
        sort (nums.begin(), nums.end());
        for (int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        for (int i=nums.size()-1;i>=0;i--)
        {
            if (sum_subarray<=sum-sum_subarray)
            {
                sum_subarray+=nums[i];
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums={4,3,10,9,8};  //4 4 6 7 7  3 4 8 9 10
    vector<int> res;
    Solution Slo;
    res=Slo.minSubsequence(nums);
    cout << endl;
    for (int i=0;i<res.size();i++)
    {
        cout << res[i] <<" ";
    }
}