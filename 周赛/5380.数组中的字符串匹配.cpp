
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for (string word:words)
        {
            for (int i=1;i<words.size();i++)
            {
                auto found = word.find(words[i]);
                if (found!=string::npos)
                {
                    res.push_back(words[i]);
                }
            }
        }
        return res;
    }
};
