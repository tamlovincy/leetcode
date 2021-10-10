/*
 * File: 283.移动零.cpp
 * Project: 20201119
 * File Created: Thursday, 19th November 2020 10:54:00 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Thursday, 19th November 2020 10:54:52 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    static void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        while(i<j){
            if (nums[i]==0){
                for (int k = i;k<j;k++){
                    nums[k]=nums[k+1];
                }
                nums[j]=0;
                j--;
            }
            else{
                i++;
            }
        }
    }
};

void swp(int &a, int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}

int main(){

    vector<int> nums = {0,0,1};
    Solution::moveZeroes(nums);
    for (int i=0;i<nums.size();i++){
        cout << nums [i] << " ";
    }
    cout << endl;
    int a = 1;
    int b = 2;
    swp(a,b);
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    return 0;
}