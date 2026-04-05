/*
 * @Author: Dragon-qing
 * @Date: 2026-03-26
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\utils\common.cpp
 * @Description: 通用函数
 */
#include "common.h"

std::vector<std::vector<int>> Read2DVectorIntFromFile(const std::string& filepath) {
    std::ifstream inFile(filepath);
    std::vector<std::vector<int>> result;
    if (!inFile.is_open()) {
        std::cerr << "can't open file: " << filepath << std::endl;
        return result;
    }

    std::string content;
    std::getline(inFile, content);  // 读取整行内容
    inFile.close();

    std::vector<int> currentVec;
    std::string numStr;
    for (char ch : content) {
        if (isdigit(ch) || ch == '-' ) {  // 处理数字，包括负数
            numStr += ch;
        } else if (ch == ',' || ch == ']') {
            if (!numStr.empty()) {
                currentVec.push_back(stoi(numStr));
                numStr.clear();
            }
            if (ch == ']') {
                if (!currentVec.empty()) {
                    result.push_back(currentVec);
                    currentVec.clear();
                }
            }
        }
    }

    return result;
}
