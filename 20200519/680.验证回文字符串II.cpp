/*
 * @Author: Lingtan 
 * @Date: 2020-05-19 09:38:00 
 * @Last Modified by: Lingtan
 * @Last Modified time: 2020-05-19 10:32:32
 */
/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
示例 1:

输入: "aba"
输出: True

示例 2:

输入: "abca"
输出: True
解释: 你可以删除c字符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome-ii
*/
#include <iostream>
#include <string>
using namespace std;

// class Solution {
// private:
//     bool isPalindrome(string s)
//     {
//         for (int i=0;i<s.length();i++)
//         {
//             if (s[i]!=s[s.length()-i-1]) return false;
//         }
//         return true;
//     }
// public:
//     bool validPalindrome(string s) {
//         if (isPalindrome(s)) return true;
//         for (int i = 0; i < s.length(); i++)
//         {
//             string sub_s;
//             for (int j=0;j<s.length();j++)
//             {
//                 if (j!=i)
//                 {
//                     sub_s+=s[j];
//                 }
//             }
//             if (isPalindrome(sub_s)) return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        
        
    }
};

int main ()
{
    string s="abca";
    Solution Sol;
    cout << Sol.validPalindrome(s) << endl;
    return 0;
}