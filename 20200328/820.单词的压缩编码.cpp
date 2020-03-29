/*
 * File: 820.单词的压缩编码.cpp
 * Project: 20200328
 * File Created: Saturday, 28th March 2020 11:07:17 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Saturday, 28th March 2020 11:07:28 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。

例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。

对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。

那么成功对给定单词列表进行编码的最小字符串长度是多少呢？

示例：

输入: words = ["time", "me", "bell"]
输出: 10
说明: S = "time#bell#" ， indexes = [0, 2, 5] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/short-encoding-of-words
*/
#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> good(words.begin(), words.end());
        for (const string& word: words) {
            for (int k = 1; k < word.size(); ++k) {
                good.erase(word.substr(k));
            }
        }
        int ans = 0;
        for (const string& word: good) {
            ans += word.size() + 1;
        }
        return ans;
    }
};


int main ()
{
//   string str="We think in generalities, but we live in details.";
//   string str2 = str.substr (3,5);     // "think" 5代表子串的长度
//   size_t pos = str.find("live");      // position of "live" in str
//   string str3 = str.substr (pos);     // get from "live" to the end
//   cout << str2 << ' ' << str3 << '\n';
    vector<string> words={"time", "me", "bell"};
    unordered_set<string> good(words.begin(), words.end());
    for (auto iter=good.begin();iter!=good.end();iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    for (const string& word: words) 
    {
        for (int k = 1; k < word.size(); ++k) 
        {
            cout << word.substr(k) << " ";
            good.erase(word.substr(k));
        }
    }
    cout << endl;
    for (auto iter=good.begin();iter!=good.end();iter++)
    {
        cout << *iter << " ";
    }

    return 0;
}