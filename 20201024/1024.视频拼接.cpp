#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool compare (vector<int> a,vector<int> b){
        return a[a.size()-1]>b[b.size()-1]; //按数组最后一个元素升序排列，如果改为return a>b，则为降序
        // return b[1] - a[1];
    }
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort (clips.begin(), clips.end(),compare);
        int cur = T, cnt = 0, i = 0;
        while(T != 0){
            if(i < clips.size() && clips[i][1] >= T){
                cur = min(cur, clips[i][0]);
                i++;
            }else{
                if(cur < T){
                    T = cur;
                    cnt++;
                }else{
                    return -1;
                }
            }
        }
        return cnt;
    }
};

int main() {
    vector<vector<int>> clips = {{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
    int T = 10;

    return 0;
}