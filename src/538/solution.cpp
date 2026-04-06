/*
 * @Author: Dragon-qing
 * @Date: 2026-04-06
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\538\solution.cpp
 * @Description: 二叉搜索树转换为累加树, 反中序遍历
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    void DFS(TreeNode *node)
    {
        if (!node) return;
        DFS(node->right);
        if (m_pPrev != nullptr)
        {
            node->val += m_pPrev->val;
        }
        m_pPrev = node;
        DFS(node->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        m_pPrev = nullptr;
        DFS(root);
        return root;
    }
private:
    TreeNode *m_pPrev;
};
// @lc code=end

