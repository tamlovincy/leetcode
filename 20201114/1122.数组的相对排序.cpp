/*
 * File: 1122.数组的相对排序.cpp
 * Project: 20201114
 * File Created: Saturday, 14th November 2020 10:43:05 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Saturday, 14th November 2020 10:43:24 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    static vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        map<int,int> arr1_map;
        for (int i=0;i<arr1.size();i++){
            arr1_map[arr1[i]]++;
        }
        for (int i=0;i<arr2.size();i++){
            for (int j=0;j<arr1_map[arr2[i]];j++){
                res.push_back(arr2[i]);
            }
            arr1_map[arr2[i]] = -1;
        }
        for (auto iter=arr1_map.begin();iter!=arr1_map.end();iter++){
            if (iter->second != -1){
                for (int i=0;i<iter->second;i++){
                    res.push_back(iter->first); 
                }
            }
        }
        return res;
    }
};


int main(){
    vector<int> arr1 = {2,21,43,38,0,42,33,7,24,13,12,27,12,24,5,23,29,48,30,31};
    vector<int> arr2 = {2,42,38,0,43,21};
    vector<int> res = Solution::relativeSortArray(arr1,arr2);
    for (int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}