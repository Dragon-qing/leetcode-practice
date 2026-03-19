/*
 * @Author: Dragon-qing
 * @Date: 2026-03-19
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\25\solution.cpp
 * @Description: 链表，反转
 * @note: 将翻转提取出来作为一个函数可以使得逻辑更清晰。
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *tempNode = new ListNode(0);
        ListNode *slow = dummy, *fast = dummy;
        while (fast != nullptr && fast->next != nullptr)
        {
            ListNode *tmpSlow = slow->next; // 记录翻转后，slow指针的位置
            int n = k;
            while (fast->next != nullptr && n > 0)
            {
                fast = fast->next;
                n--;
            }
            if (n > 0) // 不足则保持原有顺序
            {
                break;
            }
            ListNode *cur = slow->next, *ptr = nullptr;
            tempNode->next = fast->next;
            while (cur != fast && cur != nullptr)
            {
                ptr = cur->next;
                cur->next = tempNode->next;
                tempNode->next = cur;
                cur = ptr;
            }
            cur->next = tempNode->next;
            tempNode->next = cur;
            slow->next = tempNode->next;
            fast = tmpSlow;
            slow = tmpSlow;
        }
        ListNode *res = dummy->next;
        delete dummy;
        delete tempNode;
        return res;
    }
};
// @lc code=end
/**
 * @brief:通过数组构造链表 
 * @param {vector<int>} arr: 输入数组
 * @return {*}链表头指针
 */
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
    ListNode *head = CreatList({1,2,3,4});
    Solution s;
    s.reverseKGroup(head, 2);
    return 0;
}
