#include<iostream>
#include<map>
#include<string>
using namespace std;

class Solution_ {
public:
    bool isLongPressedName(string name, string typed) {
        map<char,int> map_1;
        map<char,int> map_2;
        for (int i=0;i<name.length();i++){
            map_1[name[i]]++;
        }
        for (int i=0;i<typed.length();i++){
            map_2[typed[i]]++;
        }
        cout << map_1.size() << " " <<map_2.size() << endl;
        if (map_1.size()!=map_2.size()) return false;
        auto iter_1 = map_1.begin();
        auto iter_2 = map_2.begin();
        while(iter_1!=map_1.end()){
            if (iter_1->first!=iter_2->first) return false;
            else if (iter_1->first==iter_2->first){
                if (iter_1->second>iter_2->second) return false;
            }
            iter_1++;
            iter_2++;
        }
        return true;
    }
};

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (j < typed.length()) {
            if (i < name.length() && name[i] == typed[j]) {
                i++;
                j++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            } else {
                return false;
            }
        }
        return i == name.length();
    }
};

int main(){
    string name = "kikcxmvzi";
    string typed = "kiikcxxmmvvzz";
    // string name = "alex";
    // string typed = "aaleex";
    Solution Slo;
    cout << Slo.isLongPressedName(name,typed) << endl;
    return 0;
}