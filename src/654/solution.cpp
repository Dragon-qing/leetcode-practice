/*
 * @Author: Dragon-qing
 * @Date: 2026-03-30
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\654\solution.cpp
 * @Description: 构建最大二叉树，DFS
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode *DFS(vector<int> &nums, int left, int right)
    {
        if (left >= right) return nullptr;
        int maxIdx = left;
        int maxVaule = nums[left];
        for (int i = left; i < right; i++)
        {
            if (nums[i] > maxVaule)
            {
                maxVaule = nums[i];
                maxIdx = i;
            }
        }
        TreeNode *node = new TreeNode(maxVaule);
        if (left + 1 == right) // 叶子节点
        {
            return node;
        }
        node->left = DFS(nums, left, maxIdx);
        node->right = DFS(nums, maxIdx + 1, right);
        return node;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return DFS(nums, 0, nums.size());
    }
};
// @lc code=end
