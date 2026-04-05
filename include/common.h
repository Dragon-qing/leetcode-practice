/*
 * @Author: Dragon-qing
 * @Date: 2026-03-26
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\include\common.h
 * @Description: 通用函数头文件
 */
#ifndef COMMON_H
#define COMMON_H

#include <bits/stdc++.h>

/**
 * @brief: 读取文件中的数据转化为二维vector<int>
 * @note: 数据格式为：[[1,4],[2,3]]
 * @param {string&} filepath 文件地址
 * @return {std::vector<std::vector<int>>}
 */
std::vector<std::vector<int>> Read2DVectorIntFromFile(const std::string& filepath);

/**
 * @brief: 打印输出
 * @param {vector<T>} vec: 待打印数组
 * @return {void}
 */
template<typename T>
void PromptOut(const std::vector<T> &vec)
{
    int n = vec.size();
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << vec[i] << ',';
    }
    if (n >= 1)
    {
        std::cout << vec[n - 1] << std::endl;
    }
}
#endif
