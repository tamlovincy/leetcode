//method 1 first ak
/*
 * File: 34.在排序数组中查找元素的第一个和最后一个位置.cpp
 * Project: 20201201
 * File Created: Tuesday, 1st December 2020 11:37:11 pm
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Tuesday, 1st December 2020 11:37:44 pm
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
*/
#include<iostream>
#include<vector>
using namespace std;


class Solution_1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int start = -1;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==target) {
                start = i;
                break;
            } 
        }
        if (start==-1) return {-1,-1};
        res.push_back(start);
        int end = start;
        for(int i=start;i<nums.size();i++){
            if (nums[i]!=target){
                break;
            }
            end = i;
        }
        res.push_back(end);
        return res;
    }
};
// method 2
class Solution_2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0) return {-1,-1};
        if (nums.size()==1){
            if (nums[0]==target) return {0,0};
            else return {-1,-1};
        }
        vector<int> res;
        int left = 0;
        int right = nums.size()-1;
        while(left<right){
            int mid = left+right>>1;
            if (nums[mid]>=target) right=mid;
            else left = mid+1; //find left value == target
        }
        if (nums[left]!=target) return {-1,-1};
        res.push_back(left);
        int end = left;
        for(int i=left;i<nums.size();i++){
            if (nums[i]!=target){
                break;
            }
            end = i;
        }
        res.push_back(end);
        return res;
    }
};
//method 3
class Solution_3 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0) return {-1,-1};
        if (nums.size()==1){
            if (nums[0]==target) return {0,0};
            else return {-1,-1};
        }
        vector<int> res;
        int left = 0;
        int right = nums.size()-1;
        while(left<right){
            int mid = left+right>>1;
            if (nums[mid]>=target) right=mid;
            else left = mid+1;
        }
        if (nums[left]!=target) return {-1,-1};
        res.push_back(left);
        int ll = 0;
        int rr = nums.size()-1;
        while(ll<rr){
            int mid = ll+rr+1>>1;
            if (nums[mid]<=target) ll=mid;
            else rr = mid-1;
        }
        res.push_back(rr);
        return res;
    }
};

int main(){

    
    return 0;
}