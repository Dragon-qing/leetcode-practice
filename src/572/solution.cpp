/*
 * @Author: Dragon-qing
 * @Date: 2026-03-22
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\572\solution.cpp
 * @Description: 二叉树，DFS
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool Compare(TreeNode* p, TreeNode* q) {
        if (p == q && p == nullptr) return true;
        else if (q == nullptr && p != nullptr) return false;
        else if (p == nullptr && q != nullptr) return false;
        else if (p->val != q->val) return false;
        bool left = Compare(p->left, q->left);
        bool right = Compare(p->right, q->right);
        return left && right;
    }
    bool DFS(TreeNode* node1, TreeNode* node2)
    {

        if (node1 == nullptr) return false;
        bool midAns = Compare(node1, node2);
        bool leftAns = DFS(node1->left, node2);
        bool rightAns = DFS(node1->right, node2);

        return midAns || leftAns || rightAns;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return DFS(root, subRoot);
    }
};
// @lc code=end

