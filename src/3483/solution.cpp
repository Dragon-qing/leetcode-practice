/*
 * @Author: Dragon-qing
 * @Date: 2026-09-11
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3483\solution.cpp
 * @Description: 回溯，哈希
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3483 lang=cpp
 *
 * [3483] 不同三位偶数的数目
 */

// @lc code=start
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        ans = 0;
        path = 0;
        used.resize(n, false);

        BackTracking(digits, 0);
        return ans;
    }

    void BackTracking(vector<int>& digits, int num) {
        if (num == 3) {
            if (path % 2 == 0 && !hash.contains(path)) {
                ans += 1;
                hash.insert(path);
            }
            return;
        }

        for (int i = 0; i < digits.size(); i++) {
            if (used[i] || (num == 0 && digits[i] == 0)) {continue;}

            used[i] = true;
            path = path * 10 + digits[i];
            BackTracking(digits, num + 1);
            used[i] = false;
            path /= 10;
        }
    }
private:
    unordered_set<int> hash;
    vector<bool> used;
    int path;
    int ans;

};
// @lc code=end

