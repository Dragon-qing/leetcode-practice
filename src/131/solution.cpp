/*
 * @Author: Dragon-qing
 * @Date: 2026-09-01
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\131\solution.cpp
 * @Description: 回溯，记忆化搜素
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        memo.resize(n, vector<int>(n , -1));

        string_view view(s);
        BackTracking(0, n - 1, n, view);
        return ans;
    }

    void BackTracking(int left, int right, int remain, string_view s)
    {
        if (remain == 0) {
            // 切割完成
            ans.push_back(curVec);
            return;
        }

        for (int sep = left; sep <= right; sep++) {
            int leftLen = sep - left + 1;
            if (check(s.substr(left, leftLen), left, sep)) {
                curVec.push_back(string(s.substr(left, leftLen)));
                BackTracking(sep + 1, right, remain - leftLen, s);
                curVec.pop_back();
            }
        }

    }
private:
    vector<vector<string>> ans;
    vector<string> curVec;
    vector<vector<int>> memo;// 记录回文状态，[i,j]是否为回文串
    /**
     * @brief: 检查是否为回文
     * @param {string_view} s: 字符串视图 
     * @return {bool} 结果
     */
    bool check(string_view s, int left, int right)
    {
        if (memo[left][right] != -1) {
            return memo[left][right] == 1 ? true : false;
        }
        if (s.size() == 0) return false;
        int a = 0, b = s.size() - 1;
        while (a < b) {
            if (s[a] != s[b]) {
                memo[left][right] = 0;
                return false;
            }
            a++;
            b--;
        }

        memo[left][right] = 1;
        return true;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.partition("aab");
    return 0;
}
