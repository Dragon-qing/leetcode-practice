/*
 * @Author: Dragon-qing
 * @Date: 2026-03-22
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\543\solution.cpp
 * @Description: 二叉树，DFS
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int DFS(TreeNode* node, int& ans)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int left = DFS(node->left, ans);
        int right = DFS(node->right, ans);
        if (left + right > ans)
        {
            ans = left + right;
        }
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        DFS(root, ans);
        return ans;
    }
};
// @lc code=end

