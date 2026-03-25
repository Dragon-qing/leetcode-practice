/*
 * @Author: Dragon-qing
 * @Date: 2026-03-25
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\257\solution.cpp
 * @Description: 二叉树，回溯
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void SearchPath(TreeNode* node, vector<int>& path, vector<string>& result)
    {
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr)
        {
            string s;
            for (int i = 0; i < path.size() - 1; i++)
            {
                s += to_string(path[i]);
                s += "->";
            }
            s += to_string(path.back());
            result.push_back(s);
            return;
        }

        if (node->left)
        {
            SearchPath(node->left, path, result);
            path.pop_back();
        }
        if (node->right)
        {
            SearchPath(node->right, path, result);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        SearchPath(root, path, result);
        return result;
    }
};
// @lc code=end

