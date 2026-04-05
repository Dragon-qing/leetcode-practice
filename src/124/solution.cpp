/*
 * @Author: Dragon-qing
 * @Date: 2026-04-05
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\124\solution.cpp
 * @Description: 二叉树中最大路径
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

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
    int DFS(TreeNode *node)
    {
        if (node == nullptr) return 0;
        if (node->left == nullptr && node->right == nullptr)
        {
            m_nSumMax = max(node->val, m_nSumMax);
            return node->val;
        }
        int leftSum = max(DFS(node->left), 0);
        int rightSum = max(DFS(node->right), 0);
        int curSum = leftSum + rightSum + node->val;
        m_nSumMax = max(curSum, m_nSumMax);
        return node->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        m_nSumMax = INT32_MIN;
        DFS(root);
        return m_nSumMax;
    }
private:
    int m_nSumMax;
};
// @lc code=end

