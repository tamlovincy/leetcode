/*
 * File: 836.矩形重叠.cpp
 * Project: 20200318
 * File Created: Saturday, 21st March 2020 11:07:24 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Saturday, 21st March 2020 11:07:56 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标。
如果相交的面积为正，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。
给出两个矩形，判断它们是否重叠并返回结果。

示例 1：

输入：rec1 = [0,0,2,2], rec2 = [1,1,3,3]
输出：true
示例 2：

输入：rec1 = [0,0,1,1], rec2 = [1,0,2,1]
输出：false
*/
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // if ((abs(rec2[2]-rec1[0])<rec2[2]-rec2[0]+rec1[2]-rec1[0]&&abs(rec2[3]-rec1[1])<rec2[3]-rec2[1]+rec1[3]-rec1[1]) && (abs(rec1[2]-rec2[0])<rec1[2]-rec1[0]+rec2[2]-rec2[0]&&abs(rec1[3]-rec2[1])<rec1[3]-rec1[1]+rec2[3]-rec2[1]))
        if (rec1[0]>=rec2[2]||rec2[0]>=rec1[2]||rec1[1]>=rec2[3]||rec2[1]>=rec1[3])
        {
            return false;;
        }
        return true;
    }
};