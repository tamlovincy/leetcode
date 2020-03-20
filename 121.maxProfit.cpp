/*
滑动窗口法
*/
#include <iostream>
#include <vector>
using namespace std;

//官方题解，动态规划
class solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};

//滑动窗口法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int begin=0;
        int end;
        int pro =0;
        int cache=0;
        for (end=1;end<prices.size();end++ )
        {
            if (prices[begin]>prices[end])
            {
                begin=end;
            }
            cache = prices[end]-prices[begin];
            pro = cache>pro?cache:pro;
        }
        return pro;
    }
};

int main()
{
    Solution Slo;
    vector<int> test={5,2,3,4,1};
    cout << "卖出的股票最大利润为：" <<Slo.maxProfit(test) <<endl;
    return 0;
}