#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;
    Node() : val(0), next(nullptr){}
    Node(int val, Node *next) : val(val), next(next){}
};

class MyLinkedList {
public:
    MyLinkedList() {
        m_pDummyNode = new Node();
        m_pHead = m_pDummyNode->next;
        m_pTail = m_pHead;
        m_nSize = 0;
    }
    
    int get(int index) {
        if (index < 0 || index > m_nSize - 1)
        {
            return -1;
        }

        Node *tmp = m_pHead;
        for (int i = 0; i < index; i++)
        {
            tmp = tmp->next;
        }

        return tmp->val;
    }
    
    void addAtHead(int val) {
        Node *node = new Node(val, m_pHead);
        m_pDummyNode->next = node;
        m_pHead = node;
        m_nSize++;
        if (m_pTail == nullptr)
        {
            m_pTail = node;
        }
    }
    
    void addAtTail(int val) {
        Node *node = new Node(val, nullptr);
        if (m_pTail == nullptr)
        {
            m_pTail = node;
            m_pHead = node;
            m_pDummyNode->next = node;
        }
        else
        {
            m_pTail->next = node;
            m_pTail = node;
        }
        m_nSize++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > m_nSize)
        {
            return;
        }

        if (index == 0)
        {
            addAtHead(val);
        }
        else if (index == m_nSize)
        {
            addAtTail(val);
        }
        else
        {
            Node *cur = m_pDummyNode;
            while(index--)
            {
                cur = cur->next;
            }
            Node *node = new Node(val, cur->next);
            cur->next = node;
            m_nSize++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= m_nSize)
        {
            return;
        }
        Node *cur = m_pHead;
        Node *pre = m_pDummyNode;
        if (index == 0)
        {
            m_pDummyNode->next = m_pHead->next;
            delete m_pHead;
            m_pHead = m_pDummyNode->next;
            if (m_nSize == 1)
            {
                m_pTail = nullptr;
            }
        }
        else
        {
            int count = index;
            while (count--)
            {
                cur = cur->next;
                pre = pre->next;
            }
            pre->next = cur->next;
            delete cur;
            if (index == m_nSize - 1)
            {
                m_pTail = pre;
            }
        }
        m_nSize--;
    }
private:
    Node *m_pHead;
    Node *m_pTail;
    Node *m_pDummyNode;
    int m_nSize;
};

/**
 Your MyLinkedList object will be instantiated and called as such:
 */
int main()
{
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    int param_1 = obj->get(1);
    obj->deleteAtIndex(0);
    int param_2 = obj->get(0);
    return 0;
}