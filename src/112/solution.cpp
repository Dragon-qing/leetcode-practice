/*
 * @Author: Dragon-qing
 * @Date: 2026-03-26
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\112\solution.cpp
 * @Description: 二叉树，DFS
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool DFS(TreeNode* node, int targetSum, int sum)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            if (sum + node->val == targetSum) return true;
    
            return false;
        }
        bool leftRes = false, rightRes = false;
        if (node->left)
        {
            leftRes = DFS(node->left, targetSum, sum + node->val);
        }
        if (node->right)
        {
            rightRes = DFS(node->right, targetSum, sum + node->val);
        }
        return leftRes || rightRes;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return DFS(root, targetSum, 0);
    }
};
// @lc code=end

