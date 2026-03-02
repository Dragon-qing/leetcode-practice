/*
 * @Author: Dragon-qing
 * @Date: 2026-03-02
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\160\main.cpp
 * @Description: 交叉链表
 */
# include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA, *curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != NULL)
        {
            lenA++;
            curA = curA->next;
        }
        while (curB != NULL)
        {
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if (lenA < lenB)
        {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        int gap = lenA - lenB;
        while (gap--)
        {
            curA = curA->next;
        }
        while (curA != NULL)
        {
            if (curA == curB)
            {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};

int main()
{
    Solution s;
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);  
    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    headB->next->next->next = headA->next->next;
    cout << s.getIntersectionNode(headA, headB)->val << endl;

    return 0;
}