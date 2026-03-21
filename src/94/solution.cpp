/*
 * @Author: Dragon-qing
 * @Date: 2026-03-20
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\94\solution.cpp
 * @Description: 二叉树，中序遍历
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr)
        {
            return {};
        }
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode *node = root;
        while(!st.empty() || node != nullptr)
        {
            while (node != nullptr)
            {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            ans.push_back(node->val);

            node = node->right;
        }
        return ans;
    }
};
// @lc code=end

