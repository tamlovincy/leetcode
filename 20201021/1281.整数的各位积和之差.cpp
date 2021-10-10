#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        if (n<10) return 0;
        if (n==10) return -1;
        vector<int> num;
        while(n>=10){
            int m = n%10;
            num.push_back(m);
            cout << m << endl;
            n=n/10;
        }
        num.push_back(n);
        cout << n << endl;
        int mux = 1;
        int add = 0;
        for (int i=0;i<num.size();i++){
            mux *= num[i];
            add += num[i];
        }
        return mux - add;
    }
};

int main(){
    Solution Slo;
    int n = 10255;
    cout << Slo.subtractProductAndSum(n) << endl;

    return 0;
}