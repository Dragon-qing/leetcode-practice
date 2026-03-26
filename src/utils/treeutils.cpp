/*
 * @Author: Dragon-qing
 * @Date: 2026-03-26
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\utils\treeutils.cpp
 * @Description: 树相关工具
 */
#include "treeutils.h"
TreeNode* BuildTree(std::vector<int> &arr, int idx = 0)
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