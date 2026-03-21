/*
 * @Author: Dragon-qing
 * @Date: 2026-03-21
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\429\solution.cpp
 * @Description: 二叉树，层序遍历
 */
/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        vector<vector<int>> result;
        queue<Node*> que;
        que.push(root);
        while (!que.empty())
        {
            int n = que.size();
            vector<int> vec;
            for (int i = 0; i < n; i++)
            {
                Node *node = que.front();
                que.pop();
                vec.push_back(node->val);
                for (auto tmpN : node->children)
                {
                    if (tmpN) que.push(tmpN);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};
// @lc code=end

