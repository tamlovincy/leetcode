#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int numSteps(string s) {
        int num=0;
        int count=0;
        int mi=s.size()-1;
        for (int i =0;i<s.size();i++)
        {
            num+=s[i]*pow(2,mi);
            cout << num << " ";
            mi--;
        }
        cout << num << endl;
        while (num!=1)
        {
            if (num%2==0)
            {
                count++;
                num=num/2;
            }
            else
            {
                count++;
                num+=1;
            }
        }
        return count;
    }
};

int main()
{
    string s="1101";
    Solution Slo;
    cout << Slo.numSteps(s);
}