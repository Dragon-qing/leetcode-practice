/*
 * @Author: Dragon-qing
 * @Date: 2026-06-15
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2130\solution.cpp
 * @Description: 链表，双指针
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 *
 * [2130] 链表最大孪生和
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
    int pairSum(ListNode* head) {
        int maxVal = 0;
        ListNode* mid = head;
        ListNode* fast = head;
        array<int, 50000> arr{};
        int tmp = 0;
        while (fast != nullptr) {
            arr[tmp] = mid->val;
            fast = fast->next->next;
            mid = mid->next;
            tmp++;
        }

        tmp--;
        while (mid != nullptr) {
            maxVal = max(maxVal, arr[tmp] + mid->val);
            tmp--;
            mid = mid->next;
        }

        return maxVal;
    }
};
// @lc code=end

int main()
{
    Solution s;
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout << s.pairSum(head) << endl;
    return 0;
}
