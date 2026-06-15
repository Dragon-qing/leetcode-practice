/*
 * @Author: Dragon-qing
 * @Date: 2026-06-15
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2095\solution.cpp
 * @Description: 链表、双指针
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=2095 lang=cpp
 *
 * [2095] 删除链表的中间节点
 */

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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return nullptr;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = slow->next;
        slow->next = nullptr;
        delete slow;
        slow = nullptr;


        return dummy->next;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    s.deleteMiddle(head);
    return 0;
}

// @lc code=end

