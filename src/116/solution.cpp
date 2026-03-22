/*
 * @Author: Dragon-qing
 * @Date: 2026-03-22
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\116\solution.cpp
 * @Description: 二叉树，层序遍历
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        queue<Node*> st;
        st.push(root);
        Node *prevNode = nullptr;
        Node *node = nullptr;
        while(!st.empty())
        {
            int n = st.size();
            for (int i = 0; i < n; i++)
            {
                node = st.front();
                st.pop();
                if (i == 0)
                {
                    prevNode = node;
                }
                else
                {
                    prevNode->next = node;
                    prevNode = node;
                }
                if (node->left) st.push(node->left);
                if (node->right) st.push(node->right);
            }
            prevNode->next = NULL;
        }
        return root;
    }
};
// @lc code=end

