/*
 * @Author: Dragon-qing
 * @Date: 2026-08-31
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2058\solution.cpp
 * @Description: 单链表
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=2058 lang=cpp
 *
 * [2058] 找出临界点之间的最小和最大距离
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode *cur = head->next;
        int left = head->val;
        int right = 0;
        int idx = 2; // 第二个元素开始
        int maxDistance = 0;
        int minDistance = INT32_MAX;
        int preIdx = 0;
        int cnt = 0; // 符合条件的拐点个数I
        while (cur->next != nullptr) {
            right = cur->next->val;
            if (cur->val < left && cur->val < right ||
                cur->val > left && cur->val > right) {
                cnt++;
                if (cnt == 1) {
                    maxDistance = idx;
                } else {
                    minDistance = min(minDistance, idx - preIdx);
                }
                preIdx = idx;
            }
            idx++;
            left = cur->val;
            cur = cur->next;
        }

        if (cnt < 2) {
            return {-1, -1};
        }

        maxDistance = preIdx - maxDistance;

        return {minDistance, maxDistance};
    }
};
// @lc code=end

