#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *dummy = new Node(0);
        Node *ans = new Node(0);
        dummy->next = head;
        Node *originCur = dummy, *copyCur = ans;
        unordered_map<Node*, Node*> hashMap{}; // 原节点地址，现节点地址
        int  idx = 0;
        while(originCur->next != NULL)
        {
            originCur = originCur->next;
            Node *node = new Node(originCur->val);
            copyCur->next = node;
            hashMap[originCur] = node;
            copyCur = node;
            idx++;
        }
        copyCur = ans->next;
        originCur = dummy->next;
        while (copyCur != NULL && originCur != NULL)
        {
            Node *randomNode = originCur->random;
            if (randomNode != NULL)
            {
                copyCur->random = hashMap[randomNode];
            }
            else
            {
                copyCur->random = NULL;
            }
            copyCur = copyCur->next;
            originCur = originCur->next;
        }
        Node *ansHead = ans->next;
        delete dummy;
        delete ans;
        return ansHead;
    }
};
// @lc code=end

// @lc code=end
/**
 * @brief:通过数组构造链表 
 * @param {vector<int>} arr: 输入数组
 * @return {*}链表头指针
 */
Node* CreatList(vector<int> arr)
{
    Node *dummyNode = new Node(0);
    Node *cur = dummyNode;
    for (int i : arr)
    {
        Node *node = new Node(i);
        cur->next = node;
        cur = node;
    }
    Node *head = dummyNode->next;
    delete dummyNode;
    return head;
}

int main()
{
    Solution s;
    s.copyRandomList(CreatList({1,2,3,4,5,6}));
    return 0;
}
