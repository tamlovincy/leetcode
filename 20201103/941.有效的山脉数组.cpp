/*
 * File: 941.有效的山脉数组.cpp
 * Project: 20201103
 * File Created: Tuesday, 3rd November 2020 11:06:32 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Tuesday, 3rd November 2020 11:07:17 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution_ {
public:
    static bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if (n<=2) return false;
        int res=0;
        vector<int> left(n);
        vector<int> right(n);
        for (int i=1;i<n;i++){
            left[i] = A[i-1]<A[i] ? left[i-1]+1:0; //犯错的地方left[i] = A[i-1]<A[i] ? A[i-1]+1:0;
        }
        for (int i = n-2;i>=0;i--){
            right[i] = A[i+1]<A[i] ? left[i+1]+1:0;//犯错的地方right[i] = A[i+1]<A[i] ? A[i+1]+1:0；
        }
        for (int i = 0;i<n;i++){
            if (left[i]>0&&right[i]>0){
                res = max(res,(left[i]+right[i]+1));
            }
        }
        if (res==n) return true;
        else return false;
    }
};

class Solution {
public:
    static bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if (!n) {
            return false;
        }
        vector<int> left(n);
        for (int i = 1; i < n; ++i) {
            left[i] = (A[i - 1] < A[i] ? left[i - 1] + 1 : 0);
        }
        vector<int> right(n);
        for (int i = n - 2; i >= 0; --i) {
            right[i] = (A[i + 1] < A[i] ? right[i + 1] + 1 : 0);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (left[i] > 0 && right[i] > 0) {
                ans = max(ans, left[i] + right[i] + 1);
            }
        }
        if (ans==n) return true;
        else return false;
    }
};


int main(){

    vector<int> A = {0,3,2,1};
    cout << Solution::validMountainArray(A) << endl;
    return 0;
}