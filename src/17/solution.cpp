/*
 * @Author: Dragon-qing
 * @Date: 2026-07-01
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\17\solution.cpp
 * @Description: 字符串，回溯
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        alphaSet = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        BackTracking(0, digits);

        return ans;
    }

    void BackTracking(int curIndex, string &digits)
    {
        if (curIndex == digits.size()) {
            ans.push_back(tmp);
            return;
        }
        int idx = digits[curIndex] - '0';
        string str = alphaSet[idx];
        for (char c : str)
        {
            tmp.push_back(c);
            BackTracking(curIndex + 1, digits);
            tmp.pop_back();
        }
    }
private:
    vector<string> alphaSet;
    vector<string> ans;
    string tmp;
};
// @lc code=end

