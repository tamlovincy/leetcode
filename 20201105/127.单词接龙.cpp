/*
 * File: 127.单词接龙.cpp
 * Project: 20201105
 * File Created: Thursday, 5th November 2020 10:14:58 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Thursday, 5th November 2020 10:15:48 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */

#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:
    static int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        int res = 0;
        while(!q.empty()){
            res++;
            cout << q.front() << "->";
            for(int sz = q.size(); sz > 0; sz--){
                string hop = q.front();
                if(hop == endWord) {
                    cout <<endl;
                    return res;
                }
                q.pop();
                for(auto & w: wordList){
                    if(w.empty() || w.length() != beginWord.length()) continue;
                    int diff = 0;
                    for(int i = 0; i < w.length(); i++){
                        if(w[i] != hop[i]) ++diff;
                        if(diff > 1) break;
                    }
                    if(diff <= 1){
                        q.push(w);
                        w = "";
                    }
                }
            }
        }
        return 0;
    }
};

int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    vector<string> wordList_2 = {"hig","hog","hot","dot","dog","lot","log","cog"};
    cout << Solution::ladderLength(beginWord,endWord,wordList) << endl;

    return 0;
}