/*
 * @Author: Dragon-qing
 * @Date: 2026-03-26
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\utils\treeutils.cpp
 * @Description: 树相关工具
 */
#include <queue>
#include <stack>

#include "treeutils.h"

TreeNode* BuildBinaryTreeFromVector(const std::vector<int> &arr, int idx)
{
    if (idx >= (int)arr.size())
    {
        return nullptr;
    }
    if (arr[idx] == null)
    {
        return nullptr;
    }

    TreeNode *newNode = new TreeNode(arr[idx]);
    newNode->left = BuildBinaryTreeFromVector(arr, idx * 2 + 1);
    newNode->right = BuildBinaryTreeFromVector(arr, idx * 2 + 2);

    return newNode;
}

std::vector<int> LevelOrderTraversal(TreeNode *root)
{
    if (root == nullptr) return {};
    std::queue<TreeNode*> q;
    std::vector<int> res;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size(); // 记录此时q的大小
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            res.emplace_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return res;
}

/**
 * @brief: 重新入栈
 * @note：NormalTraversal内部函数
 * @param {stack<TreeNode*>} &st 遍历栈
 * @param {TreeNode} *node 需要处理的节点
 * @return {void}
 */
void _repush_to_traversal_stack(std::stack<TreeNode*> &st, TreeNode *node)
{
    st.emplace(node);// 重新压入
    st.emplace(nullptr);// 加入标记位
}

std::vector<int> NormalTraversal(TreeNode *root, int type)
{
    // 迭代法实现,使用nullptr标记位表示栈中前一个节点需要处理的节点
    if (root == nullptr) return {};
    std::stack<TreeNode*> st;
    st.push(root);
    TreeNode *cur = nullptr;
    std::vector<int> res;
    while (!st.empty())
    {
        cur = st.top();
        if (cur == nullptr)
        {
            st.pop();
            cur = st.top();
            st.pop();
            res.emplace_back(cur->val);
        }
        else
        {
            st.pop();

            if (type == 2) // 后序
            {
                _repush_to_traversal_stack(st, cur);
            }
            
            if (cur->right) st.push(cur->right);

            if (type == 1) // 中序
            {
                _repush_to_traversal_stack(st, cur);
            }
            if (cur->left) st.push(cur->left);

            if (type == 0) // 前序
            {
                _repush_to_traversal_stack(st, cur);
            }
        }
    }
    
    return res;
}
