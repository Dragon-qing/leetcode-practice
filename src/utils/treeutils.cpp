/*
 * @Author: Dragon-qing
 * @Date: 2026-03-26
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\utils\treeutils.cpp
 * @Description: 树相关工具
 */
#include "treeutils.h"
TreeNode* BuildBinaryTreeFromVector(std::vector<int> &arr, int idx)
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
    newNode->left = BuildBinaryTreeFromVector(arr, idx * 2 + 1);
    newNode->right = BuildBinaryTreeFromVector(arr, idx * 2 + 2);

    return newNode;
}