/*
 * @Author: Dragon-qing
 * @Date: 2026-03-21
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\104\solution.cpp
 * @Description: 二叉树，递归
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int Depth(TreeNode* node, int depth)
    {
        if (node == nullptr)
        {
            return depth - 1;
        }
        return max(Depth(node->left, depth + 1), Depth(node->right, depth + 1));
    }
    int maxDepth(TreeNode* root) {
        return Depth(root, 1);
    }
};
// @lc code=end

