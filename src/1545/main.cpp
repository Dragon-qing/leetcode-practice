/*
 * @Author: Dragon-qing
 * @Date: 2026-03-03
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1545\main.cpp
 * @Description: 递归
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        string s = BuildStr(n);
        return s.at(k - 1);
    }
private:
    /**
     * @brief: 翻转所有字符
     * @param {string} &str 待翻转字符串
     * @return {*}
     */
    void Invert(string &str)
    {
        for (char &c : str)
        {
            c = ((c - '0' + 1)% 2 ) + '0';
        }
    }
    /**
     * @brief: 创建字符串
     * @param {int} n Sn
     * @return {string} 返回创建好的字符串
     */    
    string BuildStr(int n)
    {
        if (n == 1)
        {
            return "0";
        }
        string tmp = BuildStr(n - 1);
        string res = tmp + "1";
        Invert(tmp);
        ranges::reverse(tmp);
        return res + tmp;
    }
};

int main()
{
    Solution s;
    cout << s.findKthBit(4, 11);
    return 0;
}