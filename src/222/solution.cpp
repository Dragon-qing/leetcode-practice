/*
 * @Author: Dragon-qing
 * @Date: 2026-03-24
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\222\solution.cpp
 * @Description: 平衡二叉树，节点个数
 * @note: 可以使用完全二叉树的性质计算，优化性能
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
// @lc code=end

