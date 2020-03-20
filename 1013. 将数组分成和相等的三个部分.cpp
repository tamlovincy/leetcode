/*
 * File: 1013. 将数组分成和相等的三个部分.cpp
 * Project: LeetCode
 * File Created: Wednesday, 11th March 2020 9:24:55 am
 * Author: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Wednesday, 11th March 2020 9:25:59 am
 * Modified By: Lovincy Tam (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */

/*
给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才
返回 true，否则返回 false。
形式上，如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... 
+ A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] 
+ ... + A[A.length - 1]) 就可以将数组三等分。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum

示例 1：

输出：[0,2,1,-6,6,-7,9,1,2,0,1]
输出：true
解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
*/

#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=0;
        int s_1=0;
        int s_3=0;
        int ss_1=0;         //存放sum/3==s_1的值         
        int ss_3=1;         //存放sum/3==s_3的值
        int p_1=0;          //指针
        int p_3=A.size()-1; //指针
        vector<int> pp_1;  //存放sum/3==s_3的位置
        vector<int> pp_3;  //存放sum/3==s_1的位置
        for (int i = 0; i<A.size();i++)
        {
            sum+=A[i];
        }
        if (sum%3==0)
        {
            int value = sum/3;
            while(p_3!=0&&p_1!=A.size()-1)
            {
                s_1+=A[p_1];
                s_3+=A[p_3];
                if (value==s_1)
                {
                    ss_1=s_1;
                    pp_1.push_back(p_1);
                }
                if (value==s_3)
                {
                    ss_3=s_3;
                    pp_3.push_back(p_3);
                }
                p_1++;
                p_3--;  
            }
            if (ss_1==ss_3&&pp_1[0]<pp_3[0]-1)
            {
                return true;
            }
            else return false;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    vector<int> test={1,-1,0,-1,1};
    Solution Slo;
    cout << "该数组是否能按要求分成三份：" << Slo.canThreePartsEqualSum(test)<<endl;
    return 0;
}
