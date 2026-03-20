/*
 * @Author: Dragon-qing
 * @Date: 2026-03-20
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\23\solution.cpp
 * @Description: 分治，链表
 * @note: 可以使用优先队列作为辅助，也可以实现排序
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeTwoList(ListNode *a, ListNode *b)
    {
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        while (a != nullptr && b != nullptr)
        {
            if (a->val < b->val)
            {
                cur->next = a;
                a = a->next;
            }
            else
            {
                cur->next = b;
                b = b->next;
            }
            cur = cur->next;
        }
        if (a == nullptr) cur->next = b;
        else cur->next = a;
        ListNode *res = dummyHead->next;
        delete dummyHead;
        return res;
    }
    ListNode* mergeList(vector<ListNode*>& lists, int l, int r)
    {
        if (l == r)
        {
            return lists[l];
        }
        else if (l > r)
        {
            return nullptr;
        }

        int mid = (l + r) >> 1;
        return mergeTwoList(mergeList(lists, l, mid), mergeList(lists, mid + 1, r));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeList(lists, 0, lists.size() - 1);
    }
};
// @lc code=end

