/*
 * @Author: Dragon-qing
 * @Date: 2026-03-24
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\110\solution.cpp
 * @Description: 平衡二叉树判断，DFS
 */
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */
#include <bits/stdc++.h>
using namespace std;


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
    int DFS(TreeNode* node)
    {
        if (node == nullptr) return 0;
        int leftHeight = DFS(node->left);
        int rightHeight = DFS(node->right);
        if (leftHeight == -1 || rightHeight == -1) return -1;
        if (abs(leftHeight - rightHeight) > 1) return -1;
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return DFS(root) < 0 ? false : true;
    }
};
// @lc code=end

