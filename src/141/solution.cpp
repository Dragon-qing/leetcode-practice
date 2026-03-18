/*
 * @Author: Dragon-qing
 * @Date: 2026-03-18
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\141\solution.cpp
 * @Description: 链表，双指针，哈希
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
        {
            return false;
        }
        ListNode *slow = head, *fast = head->next;
        bool ans = false;

        while (slow != fast && fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast == slow)
        {
            ans = true;
        }
        return ans;
    }
};
// @lc code=end

