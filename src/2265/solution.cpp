/*
 * @Author: Dragon-qing
 * @Date: 2026-09-10
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2265\solution.cpp
 * @Description: 二叉树遍历
 */
#include <bits/stdc++.h>
#include "datadef.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=2265 lang=cpp
 *
 * [2265] 统计值等于子树平均值的节点数
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
    int averageOfSubtree(TreeNode* root) {
        ans = 0;

        DFS(root);
        return ans;
    }
    pair<int, int> DFS(TreeNode* node)
    {
        if (node == nullptr) {
            return {0, 0};
        }
        auto [leftSum, leftSize] = DFS(node->left);
        auto [rightSum, rightSize] = DFS(node->right);

        int sum = leftSum + rightSum + node->val;
        int size = leftSize + rightSize + 1;

        if (sum / size == node->val) {
            ans += 1;
        }
        return {sum, size};
    }
private:
    int ans;
};
// @lc code=end

