/*
 * @Author: Dragon-qing
 * @Date: 2026-03-18
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\234\solution.cpp
 * @Description: 链表，双指针
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int cnt = 0;
        ListNode *pre = nullptr, *cur = head;
        while (cur != nullptr)
        {
            cur = cur->next;
            cnt += 1;
        }
        if (cnt == 1)
        { // 提前判断，防止后面访问空针
            return true;
        }
        // 修改前半段next指针
        cur = head;
        for (int i = 0; i < cnt / 2; i++)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        ListNode *cur1 = pre, *cur2 = nullptr;
        if (cnt & 1) // 奇数
        {
            cur2 = cur->next;
        }
        else
        {
            cur2 = cur;
        }
        while (cur2 != nullptr)
        {
            if (cur1->val != cur2->val)
            {
                return false;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return true;
    }
};
// @lc code=end

int main()
{
    Solution s;
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    node1->next = node2;
    // ListNode *node3 = new ListNode(2);
    // node2->next = node3;
    // ListNode *node4 = new ListNode(1);
    // node4->next = node4;
    s.isPalindrome(node1);
    return 0;
}
