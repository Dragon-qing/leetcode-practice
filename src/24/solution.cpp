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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode *cur = dummyNode;
        while(cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode *tmpNode1 = cur->next, *tmpNode2 = cur->next->next;
            cur->next = tmpNode2;
            tmpNode1->next = tmpNode2->next;
            tmpNode2->next = tmpNode1;

            cur = cur->next->next;
        }

        return dummyNode->next;
    }
};

int main()
{   
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution sol;
    head = sol.swapPairs(head);

    while(head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}