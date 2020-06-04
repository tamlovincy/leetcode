/*
 * @Author: Lingtan 
 * @Date: 2020-05-20 22:57:36 
 * @Last Modified by: Lingtan
 * @Last Modified time: 2020-05-20 23:45:51
 */
/*
给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。

示例 1：

输入：s = "eleetminicoworoep"
输出：13
解释：最长子字符串是 "leetminicowor" ，它包含 e，i，o 各 2 个，以及 0 个 a，u 。
示例 2：

输入：s = "leetcodeisgreat"
输出：5
解释：最长子字符串是 "leetc" ，其中包含 2 个 e 。
示例 3：

输入：s = "bcbcbc"
输出：6
解释：这个示例中，字符串 "bcbcbc" 本身就是最长的，因为所有的元音 a，e，i，o，u 都出现了 0 次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts
*/

#include<iostream>
#include<unordered_map>
using namespace std;

// class Solution {
// public:
//     int findTheLongestSubstring(string s) {
        
//     }
// };

int main()
{
    int a=-1;
    if (~a) cout << "Testing" << endl;

    int status=1;
    status ^= 1<<4;
    cout << status << endl;
    return 0;
}