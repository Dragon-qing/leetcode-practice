/*
 * @Author: Dragon-qing
 * @Date: 2026-03-30
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\114\solution.cpp
 * @Description: 二叉树展开为链表，DFS
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void DFS(TreeNode *cur)
    {
        if (cur == nullptr) return;
        TreeNode *left = cur->left, *right = cur->right;
        if (m_pPrev)
        {
            m_pPrev->right = cur;
        }
        cur->left = nullptr;
        m_pPrev = cur;
        DFS(left);
        DFS(right);
    }
    void flatten(TreeNode* root) {
        m_pPrev = nullptr;
        DFS(root);
    }
private:
    TreeNode *m_pPrev;
};
// @lc code=end

