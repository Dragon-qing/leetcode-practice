/*
 * @Author: Dragon-qing
 * @Date: 2026-03-26
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\106\solution.cpp
 * @Description: 二叉树，DFS
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* Build(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& poster, int posterBegin, int posterEnd)
    {
        if (posterBegin == posterEnd) // 空节点
        {
            return nullptr;
        }
        TreeNode *node = new TreeNode(poster[posterEnd - 1]);
        if (posterEnd - posterBegin == 1) // 叶子节点
        {
            return node;
        }

        // 切分前序和后序
        int cutPos = inorderBegin;
        for (int i = inorderBegin; i < inorderEnd; i++)
        {
            if (inorder[i] == node->val)
            {
                cutPos = i;
                break;
            }
        }
        int inorderLeftBegin = inorderBegin;
        int inorderLeftEnd = cutPos;
        int inorderRightBegin = cutPos + 1;
        int inorderRightEnd = inorderEnd;

        int inorderLeftSize = inorderLeftEnd - inorderLeftBegin;
        int posterLeftBegin = posterBegin;
        int posterLeftEnd = posterBegin + inorderLeftSize;
        int posterRightBegin = posterLeftEnd;
        int posterRightEnd = posterEnd - 1;
        
        node->left = Build(inorder, inorderLeftBegin, inorderLeftEnd, poster, posterLeftBegin, posterLeftEnd);
        node->right = Build(inorder, inorderRightBegin, inorderRightEnd, poster, posterRightBegin, posterRightEnd);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return Build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
// @lc code=end

