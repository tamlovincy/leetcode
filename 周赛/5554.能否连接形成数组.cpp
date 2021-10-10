/*
 * File: 5554.能否连接形成数组.cpp
 * Project: 周赛
 * File Created: Sunday, 1st November 2020 10:55:02 am
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Sunday, 1st November 2020 10:55:08 am
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    static bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int leng = 0;
        for(int i=0;i<pieces.size();i++){
            leng+=pieces[i].size();
        }
        if (arr.size()!=leng) {
            cout << "testing" << endl;
            return false;
        }
        string arr_str  = "";
        for (int i=0;i<arr.size();i++){
            arr_str+=to_string(arr[i]);
            cout << arr_str << endl;
        }
        for(int i=0;i<pieces.size();i++){
            string pie_str = "";
            for (int j=0;j<pieces[i].size();j++) pie_str+=to_string(pieces[i][j]);
            cout << pie_str << endl;
            if (arr_str.find(pie_str)==string::npos) return false;
        }
        return true;
    }
};

int main(){
    vector<int> arr = {15,88};
    vector<vector<int>> pieces = {{88},{15}};
    cout << Solution::canFormArray(arr,pieces) << endl;
    return 0;
}