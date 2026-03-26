/*
 * @Author: Dragon-qing
 * @Date: 2026-03-26
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\include\treeutils.h
 * @Description: 树相关工具头文件
 */
#ifndef TREEUTILS_H
#define TREEUTILS_H
#include <vector>
#include "datadef.h"

#define null -1
/**
 * @brief: 根据数组构建二叉树
 * @param {vector<int>} &arr 待构建数组
 * @param {int} idx 索引
 * @return {TreeNode*} 节点
 */
TreeNode* BuildBinaryTreeFromVector(std::vector<int> &arr, int idx = 0);
#endif