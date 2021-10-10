#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    double trimMean(vector<int>& arr) {
        int del_num = arr.size()*5/100;
        cout << "arr.size:" << arr.size() << endl;
        int big_sum=0;
        int small_sum=0;
        sort(arr.begin(),arr.end());
        for (int i = 0; i<arr.size(); i++){
            cout << arr [i] << " ";
        }
        cout << endl;
        for (int i=0; i < del_num; i++){
            small_sum+=arr[i];
            big_sum+=arr[arr.size()-1-i];
        }
        int arr_sum=0;
        for (int i=0; i<arr.size();i++){
            arr_sum+=arr[i];
        }
        double res = 0;
        res = (double)(arr_sum - small_sum - big_sum)/((double)(arr.size()-del_num*2));
        cout << arr_sum - small_sum - big_sum << endl;
        cout << "arr.size()-del_num*2: " << arr.size()-del_num*2 << endl;
        return res;
    }
};


int main(){
    vector<int> arr = {6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4};
    Solution Slo;
    cout << Slo.trimMean(arr) << endl;
    return 0;
}