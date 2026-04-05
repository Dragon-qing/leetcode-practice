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
TreeNode* BuildBinaryTreeFromVector(const std::vector<int> &arr, int idx = 0);

/**
 * @brief: 层序遍历二叉树
 * @param {TreeNode*} root 根节点
 * @return {vector<int>} 返回结果数组
 */
std::vector<int> LevelOrderTraversal(TreeNode* root);

/**
 * @brief: 常规遍历二叉树
 * @param {TreeNode*} root 根节点
 * @param {int} type 遍历类型（0：前序，1：中序，2：后续）
 * @return {*}
 */
std::vector<int> NormalTraversal(TreeNode* root, int type = 0);
#endif