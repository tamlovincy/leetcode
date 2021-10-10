#include<iostream>
#include<string>
using namespace std;

/*
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。

示例 1：

输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/backspace-string-compare
*/

class Solution {
public:
    string backspacecore(string str) {
        string st = "";
        if (str[0]=='#' && str.length()==1) return "";
        for (int i=0;i<str.length();i++){
            if (str[i]=='#'){
                if (!st.empty()){
                    st.pop_back();
                }
            }
            else st.push_back(str[i]);
        }
        return st;
    }
public:
    bool backspaceCompare(string S, string T) {
        string res_s = backspacecore(S);
        string res_t = backspacecore(T);
        return res_s == res_t ? true : false;
    }
};

int main(){
    string S = "ab#c";
    string T = "ad#c";
    Solution Slo;
    cout << Slo.backspaceCompare(S,T) << endl;
    return 0;
}