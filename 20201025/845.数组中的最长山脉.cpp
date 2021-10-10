#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”：
B.length >= 3
存在 0 < i < B.length - 1 使得 B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
（注意：B 可以是 A 的任意子数组，包括整个数组 A。）
给出一个整数数组 A，返回最长 “山脉” 的长度。
如果不含有 “山脉” 则返回 0。

示例 1：

输入：[2,1,4,7,3,2,5]
输出：5
解释：最长的 “山脉” 是 [1,4,7,3,2]，长度为 5。
示例 2：

输入：[2,2,2]
输出：0
解释：不含 “山脉”。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-mountain-in-array
*/

class Solution_ {
public:
    static int longestMountain(vector<int>& A) {
        if (A.size()==0 || A.size() == 1 || A.size() == 2) return 0;
        int res = 0;
        for (int i = 1; i<A.size()-1;i++){
            if (A[i-1] < A[i] && A[i+1] < A[i]){
                int left = i-1;
                int right = i+1;
                while(left > 0 && A[left-1] < A[left]) left--;
                while(right < A.size()-1 && A[right+1] < A[right]) right++;
                res = max(res,(right-left+1));
            }
        }
        return res;
    }
};

class Solution {
private:
    static int MAX (int a, int b){
        return a > b ? a : b;
    }
public:
    static int longestMountain(vector<int>& A) {
        if (A.size()==0 || A.size() == 1 || A.size() == 2) return 0;
        vector<int> left(A.size()); //dp num
        vector<int> right(A.size());
        int res = 0;
        for (int i=1;i<A.size();i++){
            left[i] = A[i-1] < A[i] ? left[i-1]+1 : 0;
            // cout << left[i] << " ";
        }
        // cout << endl;
        for (int i= A.size() - 2; i > 0; i--){
            right[i] = A[i+1] < A[i] ? right[i+1]+1 : 0;
            // cout << right[i] << " ";
        }
        // cout << endl;
        for (int i=0; i<A.size();i++){
            if (left[i] >0 && right[i] >0) {
                res = MAX(res,left[i]+right[i]+1);
            }
        }
        return res;
    }
};

int main() {
    vector<int> A = {2,1,4,7,3,2,5};
    cout << Solution::longestMountain(A) << endl;
    return 0;
}