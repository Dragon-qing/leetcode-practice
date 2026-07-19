/*
 * @Author: Dragon-qing
 * @Date: 2026-07-19
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1081\solution.cpp
 * @Description: 单调栈
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26, 0);
        vector<bool> inStack(26, false);

        for (char c : s) cnt[c - 'a']++;

        string st;
        for (char c : s) {
            int x = c - 'a';
            cnt[x]--;

            if (inStack[x]) continue;

            while (!st.empty() && st.back() > c && cnt[st.back() - 'a'] > 0) {
                inStack[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            inStack[x] = true;
        }

        return st;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.smallestSubsequence("cbacdcbc");
    return 0;
}


