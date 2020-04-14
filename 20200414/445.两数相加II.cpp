/*
 * File: 445.两数相加II.cpp
 * Project: 20200414
 * File Created: Tuesday, 14th April 2020 5:57:16 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Tuesday, 14th April 2020 6:56:05 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。
进阶：
如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
示例：
输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 8 -> 0 -> 7
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers-ii
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stack>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res=nullptr;
        int carry = 0;
        stack<int> st1;
        stack<int> st2;
        while(l1!=NULL)
        {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL)
        {
            st2.push(l2->val);
            l2 = l2->next;
        }
        while(!st1.empty()||!st2.empty() || carry>0)
        {
            int a = st1.empty()?0:st1.top();
            int b = st2.empty()?0:st2.top();
            if (!st1.empty()) st1.pop();
            if (!st2.empty()) st2.pop();
            int sum = a + b + carry;
            ListNode *node = new ListNode(sum%10);
            node->next = res;
            res = node;
            carry = sum/10;
        }
        return res;
    }
};
