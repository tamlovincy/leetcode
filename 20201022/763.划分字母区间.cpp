#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution_ {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        unordered_map<char,vector<int>> map_str;
        for (int i=0;i<S.length();i++){
            map_str[S[i]].push_back(i);
        }
        int right_v = 0;
        int left_v = 0;
        for (int i=0;i<S.length();i++){
            int max_idx = *max_element(map_str[S[i]].begin(),map_str[S[i]].end());
            if (max_idx>right_v) right_v = max_idx;
            if (i==right_v){
                res.push_back(right_v-left_v+1);
                left_v = i+1;
            }
        }
        return res;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        unordered_map<char,int> map_str;
        for (int i=0;i<S.length();i++) map_str[S[i]] = i;
        int right_v = 0;
        int left_v = 0;
        for (int i=0;i<S.length();i++){
            if (map_str[S[i]]>right_v) right_v = map_str[S[i]];
            if (i==right_v){
                res.push_back(right_v-left_v+1);
                left_v = i+1;
            }
        }
        return res;
    }
};

int main(){
    // string S = "ababcbacadefegdehijhklij";
    string S = "eaaaabaaec";
    Solution Slo;
    vector<int> res;
    res = Slo.partitionLabels(S);
    for (int i=0;i<res.size();i++){
        cout << res[i] <<endl;
    }
    return 0;
}