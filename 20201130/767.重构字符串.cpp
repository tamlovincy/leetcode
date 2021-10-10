/*
 * File: 767.重构字符串.cpp
 * Project: 20201130
 * File Created: Monday, 30th November 2020 11:04:10 pm
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Monday, 30th November 2020 11:24:58 pm
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool compare(pair<int,char> &pair_a,pair<int,char> &pair_b){
        return  pair_a.first>pair_b.first;
    }
public:
    static bool is_valid(vector<pair<int,char>> &str_v){
        bool res = false;
        for (int i=0;i<str_v.size();i++){
            if (str_v[i].first!=0) return true;
        }
        return res;
    }
public:
    static string reorganizeString(string S) {
        // sort(S.begin(),S.end());
        string res = "";
        unordered_map<char,int> str_map;
        vector<pair<int,char>> str_vec;
        int max_str_num=1;
        for (int i=0;i<S.length();i++){
            str_map[S[i]]++;
        }
        for (auto iter = str_map.begin();iter!=str_map.end();iter++){
            max_str_num = max(max_str_num,iter->second);
            pair<int,char> p(iter->second,iter->first);
            str_vec.push_back(p);
        }
        if (2*max_str_num-S.length()>=2) return "";
        if (str_map.size()<=1) return S;
        sort(str_vec.begin(),str_vec.end(),compare);
        int i=0;
        int j=1;
        while(is_valid){
            res+=str_vec[i].second;
            str_vec[i].first -= 1;
            res+=str_vec[j].second;
            str_vec[j].first -= 1;
            while (str_vec[j].first==0) j++;
            while (str_vec[i].first==0) i++; 
        }
        return res;
    }
};

int main(){

    string S = "aab";
    cout << Solution::reorganizeString(S) << endl;
    return 0;
}