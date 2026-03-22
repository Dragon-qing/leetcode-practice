#include <bits/stdc++.h>
using namespace std;
#define null -1
/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int n = 0;
        int depth = 1;
        TreeNode *node = nullptr;
        bool flag = false;
        while(!que.empty())
        {
            n = que.size();
            for (int i = 0; i < n; i++)
            {
                node = que.front();
                que.pop();
                if (node->left == nullptr && node->right == nullptr)
                {
                    flag = true;
                    break;
                }
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right); 
            }
            if (flag) break;
            depth += 1;
        }

        return depth;
    }
};
// @lc code=end

/**
 * @brief: 根据数组构建二叉树
 * @param {vector<int>} &arr 待构建数组
 * @param {int} idx 索引
 * @return {TreeNode*} 节点
 */
TreeNode* BuildTree(vector<int> &arr, int idx = 0)
{
    if (idx >= arr.size())
    {
        return nullptr;
    }
    if (arr[idx] == null)
    {
        return nullptr;
    }

    TreeNode* newNode = new TreeNode(arr[idx]);
    newNode->left = BuildTree(arr, idx * 2 + 1);
    newNode->right = BuildTree(arr, idx * 2 + 2);

    return newNode;
}

int main()
{
    Solution s;
    vector<int>v = {3,9,20,null,null,15,7};
    s.minDepth(BuildTree(v));
    return 0;
}
