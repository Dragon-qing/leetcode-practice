/*
 * @Author: Dragon-qing
 * @Date: 2026-03-21
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\515\solution.cpp
 * @Description: 二叉树，层序遍历
 */
#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
        {
            return {};
        }
        queue<TreeNode*>que;
        que.push(root);

        while(!que.empty())
        {
            int n = que.size();
            int maxValue = INT32_MIN;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                maxValue = max(maxValue, node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(maxValue);
        }
        return result;
    }
};
// @lc code=end

