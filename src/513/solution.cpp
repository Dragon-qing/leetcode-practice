/*
 * @Author: Dragon-qing
 * @Date: 2026-03-26
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\513\solution.cpp
 * @Description: 二叉树，DFS
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    void DFS(TreeNode* node, int depth)
    {
        if (node->left == nullptr && node->right == nullptr) // 叶子节点
        {
            if (depth > m_nMaxDepth)
            {
                m_nMaxDepth = depth;
                m_nResult = node->val;
            }
            return;
        }
        if (node->left)
        {
            DFS(node->left, depth + 1);
        }
        if (node->right)
        {
            DFS(node->right, depth + 1);
        }

        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        DFS(root, 0);
        return m_nResult;
    }
private:
    int m_nMaxDepth = INT32_MIN;
    int m_nResult = 0;
};
// @lc code=end

