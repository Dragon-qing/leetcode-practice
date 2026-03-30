/*
 * @Author: Dragon-qing
 * @Date: 2026-03-30
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\108\solution.cpp
 * @Description: 构建平衡二叉搜索树， DFS
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* DFS(vector<int>& nums, int begin, int end)
    {
        if (begin == end)
        {
            return nullptr;
        }
        int mid = (end + begin) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        if (begin + 1 == end) // 叶子节点
        {
            return node;
        }
        node->left = DFS(nums, begin, mid);
        node->right = DFS(nums, mid + 1, end);

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return DFS(nums, 0, nums.size());
    }
};
// @lc code=end

