/*
 * @Author: dragon-qing
 * @Date: 2026-02-24
 * @LastEditors: dragon-qing
 * @LastEditTime: 2026-02-25
 * @FilePath: \leetcode\src\1022\main.cpp
 * @Description: DFS遍历二叉树
 */
#include <iostream>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int dfs(TreeNode* root, int res)
    {
        if (root == nullptr)
        {
            return 0;
        }

        res = (res << 1) + root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            std::cout << "res=" << res << std::endl;
            return res;
        }
        return dfs(root->left, res) + dfs(root->right, res);
    }

    int sumRootToLeaf(TreeNode* root) {

        return dfs(root, 0);
    }
};

TreeNode *BuildTree(int *arr, int len, int pos)
{
    if (len < 1 || pos >= len)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(arr[pos]);

    root->left = BuildTree(arr, len, pos * 2 + 1);
    root->right = BuildTree(arr, len, pos * 2 + 2);

    return root;
}
int main()
{
    int arr[] = {1,0,1,0,1,0,1};
    int len = sizeof(arr) / sizeof(arr[0]);
    TreeNode *node = BuildTree(arr, len, 0);
    
    Solution s;
    std::cout << s.sumRootToLeaf(node);
    return 0;
}