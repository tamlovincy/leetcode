

#include<stack>
#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    static vector<int> maxDepthAfterSplit(string seq) {
        stack<int> MyStack;
        vector<int> ans(seq.size(),0);
        for (int i =0;i<seq.length();i++)
        {
            if (seq[i]=='(')
            {
                MyStack.push(i);
            }
            else if (seq[i]==')')
            {
                ans[MyStack.top()]=ans[i]=!(MyStack.size()&1); //栈中'('为奇数置为1，为偶数置为0
                MyStack.pop();
            }
        }
        return ans;
    }
};

int main()
{
    string seq = "()(())()";
    vector<int> ans = Solution::maxDepthAfterSplit(seq);
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
}
