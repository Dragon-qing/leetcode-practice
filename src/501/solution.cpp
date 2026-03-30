/*
 * @Author: Dragon-qing
 * @Date: 2026-03-30
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\501\solution.cpp
 * @Description: 二叉搜索树，dfs
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    void DFS(TreeNode* cur)
    {
        if (cur == nullptr) return;
        DFS(cur->left);
        if (m_pPrev == nullptr) // 第一个元素
        {
            m_nCnt = 1;
        }
        else if (m_pPrev->val == cur->val) // 和前一个相等
        {
            m_nCnt += 1;
        }
        else // 和前一个不等
        {
            m_nCnt = 1;
        }
        m_pPrev = cur;
        if (m_nCnt == m_nMaxCnt)
        {
            m_vResult.push_back(cur->val);
        }
        else if (m_nCnt > m_nMaxCnt)
        {
            m_vResult.clear();
            m_vResult.push_back(cur->val);
            m_nMaxCnt = m_nCnt;
        }
        
        DFS(cur->right);
    }
    vector<int> findMode(TreeNode* root) {
        m_pPrev = nullptr;
        m_nCnt = 0;
        m_nMaxCnt = 0;
        DFS(root);
        return m_vResult;
    }
private:
    vector<int> m_vResult;
    TreeNode *m_pPrev;
    int m_nCnt;
    int m_nMaxCnt;
};
// @lc code=end

