/*
 * @Author: Dragon-qing
 * @Date: 2026-03-29
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\105\solution.cpp
 * @Description: 二叉树构建，DFS, 同106
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* Build(vector<int>& preorder, int preorderBegin, int preorderEnd, vector<int>& inorder, int inorderBegin, int inorderEnd)
    {
        if (preorderBegin == preorderEnd)
        {
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[preorderBegin]);
        if (preorderBegin + 1 == preorderEnd)
        {
            return node;
        }
        int delimiterPos = inorderBegin;
        for (; delimiterPos < inorderEnd; delimiterPos++)
        {
            if (inorder[delimiterPos] == node->val) break;
        }
        int inorderLeftBegin = inorderBegin;
        int inorderLeftEnd = delimiterPos;
        int inorderRightBegin = delimiterPos + 1;
        int inorderRightEnd = inorderEnd;

        int inorderLeftSize = inorderLeftEnd - inorderLeftBegin;
        int preorderLeftBegin = preorderBegin + 1;
        int preorderLeftEnd = preorderLeftBegin + inorderLeftSize;
        int preorderRightBegin = preorderLeftEnd;
        int preorderRightEnd = preorderEnd;

        node->left = Build(preorder, preorderLeftBegin, preorderLeftEnd, inorder, inorderLeftBegin, inorderLeftEnd);
        node->right = Build(preorder, preorderRightBegin, preorderRightEnd, inorder, inorderRightBegin, inorderRightEnd); 
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return Build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
// @lc code=end
