/*
 * @Author: Dragon-qing
 * @Date: 2026-04-05
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\235\solution.cpp
 * @Description: 二叉搜索树最近公共祖先
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
        {
            return root;
        }
        if (root->val < p->val && root->val < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};
// @lc code=end

