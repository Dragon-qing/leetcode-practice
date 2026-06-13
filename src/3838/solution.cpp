/*
 * @Author: Dragon-qing
 * @Date: 2026-06-13
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3838\solution.cpp
 * @Description: 字符串
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3838 lang=cpp
 *
 * [3838] 带权单词映射
 */

// @lc code=start
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for (string s : words) {
            int sum = 0;
            for (char c : s) {
                sum += weights[c - 'a'];
            }
            res += static_cast<char>('z' - (sum % 26));
        }

        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<string> words = {"abcd","def","xyz"};
    vector<int> weights = {5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2};
    cout << s.mapWordWeights(words, weights);
    return 0;
}

