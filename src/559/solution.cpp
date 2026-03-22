/*
 * @Author: Dragon-qing
 * @Date: 2026-03-22
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\559\solution.cpp
 * @Description: n叉树，DFS
 */
/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
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
    int DFS(Node* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int depth = 0;
        for (auto n : node->children)
        {
            depth = max(depth, DFS(n));
        }
        return depth + 1;

    }
    int maxDepth(Node* root) {
        return DFS(root);
    }
};
// @lc code=end

