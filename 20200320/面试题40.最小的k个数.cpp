/*
 * File: 面试题40.最小的k个数.cpp
 * Project: LeetCode
 * File Created: Friday, 20th March 2020 9:59:57 am
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Friday, 20th March 2020 10:00:01 am
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
 /*
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

示例 1：
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

示例 2：
输入：arr = [0,1,2,1], k = 1
输出：[0]
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution_well {
private:
    struct cmp{
        bool operator() (int l1, int l2){
            return l1 > l2;
        }
    };
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        priority_queue<int, vector<int>, cmp> MinHeap; //最小堆
        for(int i = 0; i < arr.size(); i++){
            MinHeap.push(arr[i]);
        }
        for(int i = 0; i < k; i++){
            res.push_back(MinHeap.top());
            MinHeap.pop();
        }
        return res;
    }
};

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> result;
        int min_num=2147483646;
        while(1)
        {
            for (int i =0;i<arr.size();i++)
            {
                if (arr[i]<min_num)
                {
                    min_num=arr[i]; //找最小值
                }
            }
            for (int j = 0; j<arr.size();j++)
            {
                if (arr[j]==min_num)
                {
                    result.push_back(min_num);
                    arr[j]=2147483647; //给最小值得位置赋为最大值
                    min_num = 2147483646;
                    if (result.size()==k)
                    {
                        return result;
                    }
                }
            }
        }    
    }
};


int main()
{   
    vector<int> arr = {0,0,1,2,4,2,2,3,1,4};
    vector<int> result;
    Solution_well Slo;
    result = Slo.getLeastNumbers(arr,8);
    for (int i =0;i<result.size();i++)
    {
        cout <<result[i]<< " ";
    }
    cout << endl << "------------------" << endl;
    priority_queue<int,vector<int>,less<int>> max_heap;
    for (int i = 0; i <arr.size(); i++)
    {
        max_heap.push(arr[i]);
    }
    while(!max_heap.empty())
    {
        cout << max_heap.top() << " ";
        max_heap.pop();
    }

    return 0;
}