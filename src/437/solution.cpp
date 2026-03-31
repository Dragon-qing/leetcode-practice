/*
 * @Author: Dragon-qing
 * @Date: 2026-03-31
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\437\solution.cpp
 * @Description: 前缀和，DFS，二叉树
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int DFS(TreeNode *node, long long cur, int targetSum)
    {
        if (node == nullptr) return 0;

        int ret = 0;
        cur += node->val;
        if (m_mHash.contains(cur - targetSum))
        {
            ret = m_mHash[cur - targetSum];
        }
        m_mHash[cur]++;
        ret += DFS(node->left, cur, targetSum);
        ret += DFS(node->right, cur, targetSum);
        m_mHash[cur]--;

        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        m_mHash[0] = 1;
        return DFS(root, 0, targetSum);
    }
private:
    unordered_map<long long, int> m_mHash;
};
// @lc code=end

