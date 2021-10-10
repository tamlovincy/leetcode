/*
 * File: 1207.独一无二的出现次数.cpp
 * Project: 20201028
 * File Created: Wednesday, 28th October 2020 10:01:24 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Wednesday, 28th October 2020 10:01:30 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        if (arr.size()==1) return true;
        unordered_map<int,int> map_arr;
        unordered_map<int,int> map_value;
        for (int i=0;i<arr.size(); i++){
            map_arr[arr[i]]++;
        }
        for (auto iter = map_arr.begin();iter!=map_arr.end();iter++){
            map_value[iter->second]++;
        }
        for (auto iter = map_value.begin();iter!=map_value.end();iter++){
            if (iter->second>1) return false;
        }
        return true;
    }
};

int main () {
    return 0;
}