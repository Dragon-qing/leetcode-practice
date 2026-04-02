/*
 * @Author: Dragon-qing
 * @Date: 2026-04-02
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\236\solution.cpp
 * @Description: 二叉树公共祖先，中序遍历
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
        if (root == nullptr || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr && right != nullptr)
        {
            return right;
        }
        else if (left != nullptr && right == nullptr)
        {
            return left;
        }
        else if (left && right)
        {
            return root;
        }

        return nullptr;
    }
};
// @lc code=end

