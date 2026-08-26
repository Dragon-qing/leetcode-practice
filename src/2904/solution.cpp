/*
 * @Author: Dragon-qing
 * @Date: 2026-08-26
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2904\solution.cpp
 * @Description: 模拟
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2904 lang=cpp
 *
 * [2904] 最短且字典序最小的美丽子字符串
 */

// @lc code=start
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        // 检查是否至少有k个1
        int numsOfOne = 0;
        for (auto c : s) {
            if (c == '1') {
                numsOfOne += 1;
            }
            if (numsOfOne >= k) {
                break;
            }
        }
        if (numsOfOne < k) {
            return "";
        }

        int num = 0;
        string ans = s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                for (int j = i; j < s.size(); j++) {
                    if (s[j] == '1') {
                        num += 1;
                    }
                    if (num == k) {
                        string tmpStr = s.substr(i, j - i + 1);
                        if (tmpStr.size() < ans.size()) {
                            ans = tmpStr;
                        } else if (tmpStr.size() == ans.size()) {
                            ans = min(tmpStr, ans);
                        }
                        break;
                    }
                }
                num = 0;
            }
        }

        return ans;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.shortestBeautifulSubstring("100011001", 3);
    return 0;
}
