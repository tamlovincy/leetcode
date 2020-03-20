/*
 * File: 1160.拼写单词.cpp
 * Project: LeetCode
 * File Created: Tuesday, 17th March 2020 9:35:04 am
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Tuesday, 17th March 2020 9:35:09 am
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。
假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。
注意：每次拼写时，chars 中的每个字母都只能用一次。
返回词汇表 words 中你掌握的所有单词的 长度之和
示例 1：
输入：words = ["cat","bt","hat","tree"], chars = "atach"
输出：6
解释： 
可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters
*/
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> hash_map;
        unordered_map<char,int>::iterator iter;
        int count=0;
        int result=0;
        string test = "test!"; //引用传递测试
        for (int i =0;i<chars.size();i++) //计数chars
        {
            hash_map[chars[i]]+=1;
        }
        for (string str:words)
        {
            unordered_map<char,int> cache_map;
            for (int i =0; i<str.size();i++)
            {
                cache_map[str[i]]+=1;
            }
            for (iter=cache_map.begin();iter!=cache_map.end();iter++)
            {
                if (iter->second<=hash_map[iter->first]) //这个地方犯过错误，加了个分号导致出现错误
                {
                    cout << iter->first << ": " << iter->second << " <= " << iter->first << ": "<<hash_map[iter->first] <<endl;
                    count++;
                }
            }
            if (count==cache_map.size())
            {
                result+=str.size();
            }
            // cache_map.clear();
            count=0;
        }
        words.push_back(test);
        return result; //匹配的单词总和
    }
};

int main()
{
    unordered_map<char,int> hash_map;
    unordered_map<char,int>::iterator iter;
    vector<string> words = {"cat","bt","hat","tree"};
    string chars = "atach";
    // string chars = "welldonehoneyr";
    // for (int i =0;i<chars.size();i++)
    // {
    //     hash_map[chars[i]]=hash_map[chars[i]]+1;
    // }
    // for (iter=hash_map.begin();iter!=hash_map.end();iter++)
    // {
    //     cout <<iter->first<<":";
    //     cout << iter->second <<",";
    //     cout << endl;
    //     cout << hash_map[iter->first];
    // }
    Solution Slo;
    cout <<Slo.countCharacters(words,chars);
    cout << endl;
    //words引用传递测试pass_by_reference
    string test=words.back();
    for (int i =0;i<test.size();i++)
    {
        cout << test[i];
    }
    return 0;
}