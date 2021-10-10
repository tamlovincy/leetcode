/*
 * File: 1356.根据数字二进制下 1 的数目排序.cpp
 * Project: 20201106
 * File Created: Friday, 6th November 2020 11:11:16 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Friday, 6th November 2020 11:11:18 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static int cnt_bit (int num){
        if (num==0) return 0;
        if (num==1) return 1;
        int res = 0;
        while(num>1){
            res += num%2;
            // num /= 2;
            num = num >>1;
        }
        res += num;
        return res;
    }
public:
    static bool compare (int a, int b){
        if (cnt_bit(a)==cnt_bit(b)) return a < b;
        return cnt_bit(a)<cnt_bit(b);
    }
public:
    static vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};
int main(){

    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    vector<int> res = Solution::sortByBits(arr);
    for (int i=0;i<res.size();i++){
        cout << res [i] << " ";
    }
    cout << endl;
    return 0;
}