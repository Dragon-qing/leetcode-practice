/*
 * @Author: Dragon-qing
 * @Date: 2026-03-02
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\142\main.cpp
 * @Description: 环形链表
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> visited{};
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }

        ListNode *cur = head;

        while(cur != NULL)
        {
            if (visited.contains(cur))
            {
                return cur;
            }
            visited.insert(cur);
            cur = cur->next;
        }
        return NULL;
    }
}; */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        ListNode *fast = head, *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) // 两者相遇，存在圆环
            {
                ListNode *idx1 = head;
                ListNode *idx2 = fast;
                while (idx1 != idx2)
                {
                    idx1 = idx1->next;
                    idx2 = idx2->next;
                }
                return idx1;
            }
        }
        return NULL;
    }
};