/*
 * @Author: Dragon-qing
 * @Date: 2026-09-09
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\139\solution.cpp
 * @Description: 动态规划
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (string &word : wordDict) {
                int len = word.size();
                if (i - len < 0) {
                    continue;
                }
                if (s.substr(i - len, len) == word && dp[i - len]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<string> wordDict = {"leet","code"};
    s.wordBreak("leetcode", wordDict);
    return 0;
}
