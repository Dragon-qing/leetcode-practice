/*
 * @Author: Dragon-qing
 * @Date: 2026-03-03
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\445\main.cpp
 * @Description: 链表，堆栈
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curA = l1, *curB = l2, *dummyNode = new ListNode(), *head = nullptr;
        vector<int> vec1{};
        vector<int> vec2{};
        while (l1 != nullptr)
        {
            vec1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            vec2.push_back(l2->val);
            l2 = l2->next;
        }
        int loop = max(vec1.size(), vec2.size());

        int carryValue = 0;
        while (loop--)
        {
            int num1 = 0, num2 = 0;
            if (!vec1.empty())
            {
                num1 = vec1.back();
                vec1.pop_back();
            }
            if (!vec2.empty())
            {
                num2 = vec2.back();
                vec2.pop_back();
            }
            int sum = carryValue + num1 + num2;
            carryValue = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            dummyNode->next = node;
            node->next = head;
            head = node;
        }
        if (carryValue)
        {
            ListNode *node = new ListNode(carryValue, head);
            dummyNode->next = node;
            head = node;
        }
        return head;
    }
};

