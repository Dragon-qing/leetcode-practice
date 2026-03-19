/*
 * @Author: Dragon-qing
 * @Date: 2026-03-19
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\148\solution.cpp
 * @Description: 链表排序，分治法
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
/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }
    ListNode* sortList(ListNode* head, ListNode* tail)
    {
        if (head == nullptr) // 为空
        {
            return head;
        }
        if (head->next == tail) // 只有一个节点
        {
            head->next = nullptr;
            return head;
        }
        // 寻找中点
        ListNode *slow = head, *fast = head;
        while (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
            {
                fast = fast->next;
            }
        }
        return MergeList(sortList(head, slow), sortList(slow, tail));
    }
    /**
     * @brief: 合并两个链表
     * @param {ListNode*}[in] head1
     * @param {ListNode*}[in] head2
     * @return {ListNode*} 返回合并后的头节点
     */    
    ListNode* MergeList(ListNode *head1, ListNode *head2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->val < head2->val)
            {
                cur->next = head1;
                head1 = head1->next;
            }
            else
            {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        if (head1 != nullptr)
        {
            cur->next = head1;
        }
        if (head2 != nullptr)
        {
            cur->next = head2;
        }
        ListNode *res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};
// @lc code=end

ListNode* CreatList(vector<int> arr)
{
    ListNode *dummyNode = new ListNode(0);
    ListNode *cur = dummyNode;
    for (int i : arr)
    {
        ListNode *node = new ListNode(i);
        cur->next = node;
        cur = node;
    }
    ListNode *head = dummyNode->next;
    delete dummyNode;
    return head;
}

int main()
{
    Solution s;
    s.sortList(CreatList({4,2,1,3}));
    return 0;
}
