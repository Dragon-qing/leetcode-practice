/*
 * @Author: Dragon-qing
 * @Date: 2026-03-21
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\145\solution_2.cpp
 * @Description: 后序遍历
 */
#include <bits/stdc++.h>
using namespace std;

#define null -1
/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *prev = nullptr;
        TreeNode *cur = root;
        while (cur != nullptr || !st.empty())
        {
            while (cur != nullptr) // 一直向左直到叶子节点
            {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();

            if (cur->right == nullptr || prev == cur->right)
            {
                st.pop();
                ans.push_back(cur->val);
                prev = cur;
                cur = nullptr;
            }
            else
            {
                cur = cur->right;
            }
        }
        return ans;
    }
};
// @lc code=end

TreeNode* BuildTree(vector<int> &arr, int idx)
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
    vector<int> v = {
        1,null,2,null,null,3
    };
    Solution s;
    auto ans = s.postorderTraversal(BuildTree(v, 0));
    return 0;
}
