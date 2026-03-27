/*
 * @Author: Dragon-qing
 * @Date: 2026-03-26
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\113\solution.cpp
 * @Description: 二叉树，DFS
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    void DFS(TreeNode* node, int count)
    {
        if (node == nullptr)
        {
            return;
        }
        if (node->left == nullptr && node->right == nullptr)
        {
            if (node->val == count)
            {
                m_vPath.push_back(node->val);
                m_vResult.push_back(m_vPath);
                m_vPath.pop_back();
            }
            return;
        }
        if (node->left)
        {
            m_vPath.push_back(node->val);
            DFS(node->left, count - node->val);
            m_vPath.pop_back();
        }
        if (node->right)
        {
            m_vPath.push_back(node->val);
            DFS(node->right, count - node->val);
            m_vPath.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        DFS(root, targetSum);
        return m_vResult;
    }
private:
    vector<vector<int>>m_vResult;
    vector<int>m_vPath;
};
// @lc code=end

int main()
{
    
    return 0;
}

