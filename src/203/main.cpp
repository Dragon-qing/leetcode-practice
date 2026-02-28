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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyNode = new ListNode(0, head);
        ListNode *node = head;
        ListNode *pre = dummyNode;
        while(node != nullptr)
        {
            if (node->val == val)
            {
                ListNode *tmp = node;
                node = node->next;
                pre->next = node;
                tmp->next = nullptr;
                delete tmp;
            }
            else
            {
                node = node->next;
                pre = pre->next;
            }
        }

        head = dummyNode->next;
        dummyNode->next = nullptr;
        delete dummyNode;
        return head;
    }
};

int main()
{

    return 0;
}