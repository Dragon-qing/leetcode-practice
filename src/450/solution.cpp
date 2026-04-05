/*
 * @Author: Dragon-qing
 * @Date: 2026-04-05
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\450\solution.cpp
 * @Description: 删除二叉搜索树中的节点
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 1. 没找到目标值
        if (root == nullptr) return nullptr;

        if (root->val == key)
        {
            // 2.目标值为叶子节点
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            else if (root->left != nullptr && root->right == nullptr) // 3. 左子树非空
            {
                auto tNode = root->left;
                delete root;
                return tNode;
            }
            else if (root->left == nullptr && root->right != nullptr) // 4. 右子树非空
            {
                auto tNode = root->right;
                delete root;
                return tNode;
            }
            else // 5.左右子树皆非空
            {
                // 删除目标节点并保持搜索树特性
                auto cur = root->right;
                while (cur->left)
                {
                    cur = cur->left;
                }
                cur->left = root->left;
                auto tNode = root->right;
                delete root;
                return tNode; // 传递给父节点进行操作
            }
        }
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
// @lc code=end

