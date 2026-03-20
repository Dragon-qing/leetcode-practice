#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
struct DListNode{
    int key;
    int val;
    DListNode* prev;
    DListNode* next;
    DListNode() : key(0), val(0), prev(nullptr), next(nullptr){}
    DListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr){}
    DListNode(int k, int v, DListNode* p, DListNode* n) : key(k), val(v), prev(p), next(n){}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        m_nCapacity = capacity;
        m_pHead = new DListNode(-1, -1);
        m_pTail = new DListNode(-1, -1);
        m_pHead->next = m_pTail;
        m_pTail->prev = m_pHead;
        m_nSize = 0;
    }
    
    int get(int key) {
        if (!m_mHash.contains(key))
        {
            return -1;
        }
        DListNode* node = m_mHash[key];
        MoveToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (m_mHash.contains(key))
        {
            DListNode* node = m_mHash[key];
            node->val = value;
            node->key = key;
            MoveToHead(node);
            return;
        }
        DListNode* newNode = new DListNode(key, value);
        m_mHash.insert({key, newNode});
        if (m_nSize == m_nCapacity && m_nCapacity != 0)
        {
            DListNode* deleteNode = RemoveNode(m_pTail->prev);
            InsertToHead(newNode);
            m_mHash.erase(deleteNode->key);
            delete deleteNode;
        }
        else if(m_nSize < m_nCapacity)
        {
            InsertToHead(newNode);
        }
        else
        {
            delete newNode;
            m_mHash.erase(key);
        }
    }
private:
    unordered_map<int, DListNode*> m_mHash; // 哈希表
    int m_nCapacity; // 容量
    DListNode* m_pHead; // 头节点
    DListNode* m_pTail; // 尾部节点
    int m_nSize; // 当前大小

    /**
     * @brief: 移动到头节点位置
     * @param {DListNode*} node 需要移动的节点
     * @return {*}
     */
    void MoveToHead(DListNode* node)
    {
        (void)RemoveNode(node);
        InsertToHead(node);
    }

    /**
     * @brief: 移除指定节点
     * @param {DListNode*} node
     * @return {*}
     */
    DListNode* RemoveNode(DListNode* node)
    {
        if (node == nullptr)
        {
            return node;
        }
        DListNode* prevN = node->prev;
        DListNode* nextN = node->next;
        prevN->next = nextN;
        nextN->prev = prevN;
        m_nSize -= 1;
        return node;
    }

    /**
     * @brief: 插入节点到头部
     * @param {DListNode*} node
     * @return {*}
     */    
    void InsertToHead(DListNode* node)
    {
        if (node == nullptr)
        {
            return;
        }
        DListNode* nextN = m_pHead->next;
        m_pHead->next = node;
        node->prev = m_pHead;
        node->next = nextN;
        nextN->prev = node;
        m_nSize += 1;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main()
{
    LRUCache LRU(2);
    LRU.put(1, 1);
    LRU.put(2, 2);
    LRU.get(1);
    LRU.put(3, 3);
    LRU.get(2);
    LRU.put(4, 4);
    LRU.get(1);
    LRU.get(3);
    LRU.get(4);
    return 0;
}
