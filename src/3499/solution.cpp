/*
 * @Author: Dragon-qing
 * @Date: 2026-07-21
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3499\solution.cpp
 * @Description: 枚举，贪心
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3499 lang=cpp
 *
 * [3499] 操作后最大活跃区段数 I
 */

// @lc code=start
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int originNum = 0;
        vector<int> zeros;
        int length = 0;

        for (auto c : s) {
            if (c == '1') {
                originNum += 1;
                if (length != 0) {
                    zeros.push_back(length);
                    length = 0;
                }
            } else {
                length += 1;
            }
        }
        if (length != 0) {
            zeros.push_back(length);
        }

        int ans = originNum;
        if (zeros.size() >= 2) {
            int prev = zeros.front();
            int maxsum = prev;
            for (int i = 1; i < zeros.size(); i++) {
                maxsum = max(maxsum, prev + zeros[i]);
                prev = zeros[i];
            }
            ans += maxsum;
        }

        return ans;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.maxActiveSectionsAfterTrade("0100");
    return 0;
}
