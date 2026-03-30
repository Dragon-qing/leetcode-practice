/*
 * @Author: Dragon-qing
 * @Date: 2026-03-30
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\530\solution.cpp
 * @Description: 二叉搜索树，DFS
 * @note: 中序序列是非递减的有序序列
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
class Solution
{
public:
    void DFS(TreeNode *node)
    {
        if (node == nullptr) return;
        DFS(node->left);
        if (m_pPrev)
        {
            m_nRes = min(abs(node->val - m_pPrev->val), m_nRes);
        }
        m_pPrev = node;
        DFS(node->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        m_pPrev = nullptr;
        m_nRes = INT32_MAX;
        DFS(root);
        return m_nRes;
    }

private:
    TreeNode *m_pPrev;
    int m_nRes;
};
// @lc code=end
