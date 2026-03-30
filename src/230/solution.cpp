/*
 * @Author: Dragon-qing
 * @Date: 2026-03-30
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\230\solution.cpp
 * @Description: 二叉搜索树，中序遍历，DFS
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
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
    void DFS(TreeNode *node, int k)
    {
        if (node == nullptr) return;

        DFS(node->left, k);
        m_nIndex += 1;
        if (m_nIndex == k)
        {
            m_nRes = node->val;
            return;
        }
        else if (m_nIndex > k)
        {
            return;
        }
        DFS(node->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        m_nRes = 0;
        m_nIndex = 0;
        DFS(root, k);
        return m_nRes;
    }
private:
    int m_nIndex;
    int m_nRes;
};
// @lc code=end

