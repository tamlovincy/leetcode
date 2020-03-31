
#include<vector>
#include<iostream>
using namespace std;

// class Solution {
//     struct Node
//     {
//         int val;
//         Node *next;
//         Node(int v) : val(v), next(nullptr) {} //构造函数与默认参数列表
//     };
// public:
//     int lastRemaining(int n, int m) {
//         Node *p,listNode;
//         p->next=NULL;
//         for (int i=0;i<n;i++)
//         {
//             listNode = new Node(i);
//             p->next=listNode;
//             p=&listNode;
//         }
//     }
// };

// struct Node
// {
//     int val;
//     Node *next;
//     Node(int v) : val(v), next(nullptr) {} //构造函数与默认参数列表
// };

class Solution {
public:
    int lastRemaining(int n, int m) {
        vector<int> list;
        vector<int>::iterator iter;
        for (int i=0;i<n;i++)
        {
            list.push_back(i);
        }
        iter=list.begin();
        while(list.size()!=1)
        {
            if (list.end()-iter<=m)
            {
                iter=list.begin()+m-(list.end()-iter);
            }
            else   
            {
                iter+=m;
            }
            cout << *iter << " ";
            list.erase(iter);
        }
        return *iter;
    }
};

int main()
{
    return 0;
    Solution Slo;
    cout << Slo.lastRemaining(5,3);
}