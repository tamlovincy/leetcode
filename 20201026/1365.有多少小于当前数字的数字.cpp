#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> data(101,0);
        for (int i=0;i<nums.size();i++){
            data[nums[i]] += 1;
        }
        for (int i=1;i<101;i++){
            data[i] = data[i-1]+data[i];
        }
        vector<int> res(nums.size());
        for (int i=0;i<nums.size();i++){
            res[i] = nums[i] == 0 ? 0 : data[nums[i]-1];
        }
        return res;
    }
};

int main(){
    vector<int> nums = {8,1,2,2,3};
    vector<int> res = Solution::smallerNumbersThanCurrent(nums);
    for (int i=0;i<res.size();i++){
        cout << res [i] << " ";
    }
    return 0;
}