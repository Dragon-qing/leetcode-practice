/*
 * @Author: Dragon-qing
 * @Date: 2026-03-18
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\19\solution.cpp
 * @Description: 链表，双指针
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *fast = dummy, *slow = dummy;
        while (n--)
        {
            fast = fast->next;
        }
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *cur = slow->next;
        slow->next = cur->next;
        delete cur;
        return dummy->next;
    }
};
// @lc code=end

