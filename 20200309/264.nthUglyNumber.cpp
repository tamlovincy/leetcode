/*
计算出前n个丑数(只有2,3,5作为公因子的数)
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> nthUglyNumber(int n) {
        int p_2=0;
        int p_3=0;
        int p_5=0;
        int cur_uglyNumber = 1;
        vector<int> uglyNumber(n,0);
        uglyNumber[0]=1;  //初始化丑数的值
        for (int i =1; i<n;i++)
        {
            int next_2 = uglyNumber[p_2]*2;
            int next_3 = uglyNumber[p_3]*3;
            int next_5 = uglyNumber[p_5]*5;

            if (next_2<=next_3&&next_2<=next_5)
            {
                p_2++;
                cur_uglyNumber=next_2;
            }

            if(next_3<=next_2&&next_3<=next_5)
            {
                p_3++;
                cur_uglyNumber=next_3;
            }
            if(next_5<=next_2&&next_5<=next_3)
            {
                p_5++;
                cur_uglyNumber=next_5;
            }

            uglyNumber[i]=cur_uglyNumber;
        }
        // return uglyNumber[n-1];
        return uglyNumber;
    }
};

int main()
{
    Solution Slo;
    int n = 20; //打印出前n个丑数
    vector<int> uglyNums=Slo.nthUglyNumber(n);
    for (int i=0;i<uglyNums.size();i++)
    {
        cout <<uglyNums[i]<<" ";
    }
    // cout << "第"<<n<<"个丑数为："<<Slo.nthUglyNumber(n)<<endl;
    return 0;
}