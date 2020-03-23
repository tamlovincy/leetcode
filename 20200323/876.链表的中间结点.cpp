/*
 * File: 876.链表的中间结点.cpp
 * Project: 20200323
 * File Created: Monday, 23rd March 2020 9:36:16 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Monday, 23rd March 2020 9:36:21 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。
示例 1：

输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
示例 2：
输入：[1,2,3,4,5,6]
输出：此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/middle-of-the-linked-list
*/

#include<iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_leetcode {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* mid=head;
        ListNode* fast=head;
        if (!head) return NULL;
        while(fast!=NULL||fast->next!=NULL)
        {
            if (fast->next==NULL)
            {
                return mid;
            }
            else if (fast->next->next==NULL)
            {
                return mid->next;
            }
            mid = mid->next;
            fast = fast->next->next;
        }
        return mid;
    }
};

int main()
{
    //创建链表 1->2->3->4->5->6
    ListNode* head;  //ListNode list=new ListNode(0) 
    ListNode Node_1(1);
    ListNode Node_2(2);
    ListNode Node_3(3);
    ListNode Node_4(4);
    ListNode Node_5(5);
    ListNode Node_6(6);
    head = &Node_1;
    Node_1.next = &Node_2;
    Node_2.next = &Node_3;
    Node_3.next = &Node_4;
    Node_4.next = &Node_5;
    Node_5.next = &Node_6;
    Solution_leetcode Slo;
    ListNode* result = Slo.middleNode(head);
    while(result!=NULL)
    {   
        cout <<result->val<<" ";
        result = result->next;
    }
    return 0;
}