#include<iostream>
#include<vector>
using namespace std;
//****************************并查集***********************//
int unionsearch(int root,vector<int>&pre) //查找根结点
{
    int son, tmp;
    son = root;
    while(root != pre[root]){ //我的上级不是掌⻔，直到找到掌门
        root = pre[root];
        // cout << root << endl;
    }
    while(son != root) //我就找他的上级，直到掌⻔出现，重新建一张图，所有人的上司都是root的上司
    {
        tmp = pre[son];
        pre[son] = root;
        son = tmp;
    }
    return root; //掌⻔驾到~~
}

int main(){
    vector<int> pre = {3,1,1,1,2,4,2};
    // for (int i = 0;i<pre.size();i++){
    int i = 6;
        cout << i <<"的掌门人为：" << unionsearch(i,pre) << endl;
    // }
    
    return 0;
}