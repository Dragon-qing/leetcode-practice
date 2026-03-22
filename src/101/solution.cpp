/*
 * @Author: Dragon-qing
 * @Date: 2026-03-22
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\101\solution.cpp
 * @Description: 二叉树，对称
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool Compare(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right != nullptr)
        {
            return false;
        }
        else if (left != nullptr && right == nullptr)
        {
            return false;
        }
        else if (left == nullptr && right == nullptr)
        {
            return true;
        }
        else if (left->val != right->val)
        {
            return false;
        }

        bool outside = Compare(left->left, right->right);
        bool inside = Compare(left->right, right->left);
        return outside && inside;

    }
    bool isSymmetric(TreeNode* root) {
        return Compare(root->left, root->right);
    }
};
// @lc code=end

