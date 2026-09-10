/*
 * @Author: Dragon-qing
 * @Date: 2026-09-10
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\93\solution.cpp
 * @Description: 回溯，字符串
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12) {
            return {};
        }
        BackTracking(s, 0, 0);
        return ans;
    }

    void BackTracking(string& s, int startIndex, int pointNum) {
        if (pointNum == 3) {
            if (check(s, startIndex, s.size() - 1)) {
                ans.emplace_back(s);
            }
            return;
        }

        for (int i = startIndex; i < s.size(); i++) {
            if (!check(s, startIndex, i)) {
                break;
            }
            s.insert(s.begin() + i + 1, '.');
            BackTracking(s, i + 2, pointNum + 1);
            s.erase(s.begin() + i + 1);
        }
    }
private:
    vector<string> ans;

    bool check(string &s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (start < end && s[start] == '0') return false;

        int sum = 0;
        for (int i = start; i <= end; i++) {
            char c = s[i];
            if (c < '0' || c > '9') return false;
            sum = sum * 10 + (c - '0');
            if (sum > 255) return false;
        }
        return true;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.restoreIpAddresses("25525511135");
    return 0;
}
