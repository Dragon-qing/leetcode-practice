/*
 * @Author: Dragon-qing
 * @Date: 2026-03-30
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\98\solution.cpp
 * @Description: 二叉搜索树，DFS
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool DFS (TreeNode* node, long long low, long long heigh)
    {
        if (node == nullptr) return true;
        if (node->val < low || node->val > heigh) return false;
        bool leftRes = true, rightRes = true, cur = true;
        if (node->left) 
        {
            leftRes = DFS(node->left, low, (long long)node->val - 1);
        }
        if (node->right)
        {
            rightRes = DFS(node->right, (long long)node->val + 1, heigh);
        }

        return cur && leftRes && rightRes;
    }
    bool isValidBST(TreeNode* root) {
        return DFS(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};
// @lc code=end

