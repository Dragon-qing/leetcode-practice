/*
 * @Author: Dragon-qing
 * @Date: 2026-03-21
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\637\solution.cpp
 * @Description: 二叉树，层序遍历
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (root == nullptr)
        {
            return {};
        }
        queue<TreeNode*>que;
        que.push(root);

        while(!que.empty())
        {
            int n = que.size();
            double sum = 0;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                sum += node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(sum * 1.0 / n);
        }
        return result;
    }
};
// @lc code=end

