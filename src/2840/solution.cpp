/*
 * @Author: Dragon-qing
 * @Date: 2026-03-30
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2840\solution.cpp
 * @Description: 字符串，哈希
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2840 lang=cpp
 *
 * [2840] 判断通过操作能否让字符串相等 II
 */

// @lc code=start
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int hash1[2][26] = {0};
        int hash2[2][26] = {0};

        int n = s1.size();
        for (int i = 0; i < n; i++)
        {
            hash1[i % 2][s1[i] - 'a'] += 1;
            hash2[i % 2][s2[i] - 'a'] += 1;
        }

        return memcmp(hash1, hash2, sizeof(hash1)) == 0;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.checkStrings("abcdba", "cabdab");
    return 0;
}
