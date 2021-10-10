/*
 * File: 1370.上升下降字符串.cpp
 * Project: 20201125
 * File Created: Wednesday, 25th November 2020 10:52:43 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Wednesday, 25th November 2020 11:18:55 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给你一个字符串 s ，请你根据下面的算法重新构造字符串：
从 s 中选出 最小 的字符，将它 接在 结果字符串的后面。
从 s 剩余字符中选出 最小 的字符，且该字符比上一个添加的字符大，将它 接在 结果字符串后面。
重复步骤 2 ，直到你没法从 s 中选择字符。
从 s 中选出 最大 的字符，将它 接在 结果字符串的后面。
从 s 剩余字符中选出 最大 的字符，且该字符比上一个添加的字符小，将它 接在 结果字符串后面。
重复步骤 5 ，直到你没法从 s 中选择字符。
重复步骤 1 到 6 ，直到 s 中所有字符都已经被选过。
在任何一步中，如果最小或者最大字符不止一个 ，你可以选择其中任意一个，并将其添加到结果字符串。
请你返回将 s 中字符重新排序后的 结果字符串 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/increasing-decreasing-string
*/
#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    static bool is_empty(vector<int> &data){
        for (int i=0;i<data.size();i++){
            if (data[i]!=0) return false;
        }
        return true;
    }
    static string sortString(string s) {
        string res;
        // map<int,int> map_str;
        // for (int i=0;i<s.length();i++){
        //     // map_str[s[i]]++;
        //     map_str[s[i]-'a']++;
        // }
        vector<int> data(26,0);
        for (int i=0;i<s.length();i++){
            data[s[i]-'a']++;
        }
        while(!is_empty(data)){
            for (int i=0;i<data.size();i++){
                if (data[i]!=0){
                    res+=i+'a';
                    data[i]--;
                }
            }
            for (int i=data.size()-1;i>=0;i--){
                if (data[i]!=0){
                    res+=i+'a';
                    data[i]--;
                }
            }
        }
        // while(map_str.size()!=0){
        //     cout << "st1: " ;
        //     for (auto iter = map_str.begin();iter!=map_str.end();iter++){
        //         res +=iter->first+'a';
        //         cout << iter->first << ",";
        //         iter->second -= 1;
        //         if (iter->second==0) map_str.erase(iter->first);
        //     }
        //     cout << endl;
        //     cout << "st2: ";
        //     for (auto r_iter = map_str.rbegin();r_iter!=map_str.rend();r_iter++){
        //         res +=r_iter->first+'a';
        //         cout << r_iter->first << ",";
        //         r_iter->second -= 1;
        //         if (r_iter->second==0) map_str.erase(r_iter->first);
        //     }
        //     cout << endl;
        // }
        return res;
    }
};
int main(){

    string s = "aaaabbbbcccc";
    cout << Solution::sortString(s) << endl;
    return 0;
}