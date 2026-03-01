/*
 * @Author: Dragon-qing
 * @Date: 2026-02-18
 * @LastEditors: Dragon-qing
 * @LastEditTime: 2026-02-24
 * @FilePath: \leetcode\src\693\main.cpp
 * @Description: 
 */
#include <iostream>
#include <bitset>
#include <string.h>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool falg = true;
        char tmp = '\0';
        string s = bitset<32>(n).to_string();
        s = s.substr(s.find('1')); // 去除前置的0
        
        for(char c: s)
        {
            if (c == tmp)
            {
                falg = false;
                break;
            }
            tmp = c;
        }
        
        return falg;
    }
};

int main()
{
    Solution s;
    std::cout << s.hasAlternatingBits(4);
    return 0;
}