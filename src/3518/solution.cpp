/*
 * @Author: Dragon-qing
 * @Date: 2026-07-29
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3518\solution.cpp
 * @Description: 计数排序，数学
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3518 lang=cpp
 *
 * [3518] 最小回文排列 II
 */

// @lc code=start
class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        alpha.assign(26, 0);
        // 计算前半部分
        for (int i = 0; i < n / 2; i++) {
            alpha[s[i] - 'a'] += 1;
        }

        if (perm(n / 2, k) < k) {
            return "";
        }

        string leftStr(n / 2, 0);

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < 26; j++) {
                if (alpha[j] == 0) continue;
                alpha[j]--;
                long long per = perm(n / 2 - i - 1, k);
                if (per >= k) {
                    leftStr[i] = 'a' + j;
                    break;
                }
                k -= per;
                alpha[j]++;
            }
        }
        string ans = leftStr;
        if (n & 1) {
            // 总长为奇数时，加上中间的字符
            ans += s[n / 2];
        }
        ans += string(leftStr.rbegin(), leftStr.rend());
        return ans;
    }

    /**
     * @brief: 计算组合C(m)(n)
     * @param {int} m: 
     * @param {int} n: 
     * @return {*}
     */
    long long comb(int m, int n, int k) 
    {
        n = min(n, m - n); // 减少乘算的步骤，防止中间过程中res溢出
        long long res = 1;

        for (int i = 1; i <= n; i++) {
            res = res * (m - i + 1) / i;
            if (res > k) return k;
        }

        return res;
    }

    /**
     * @brief:计算排列 
     * @param {int} length: 
     * @return {*}
     */
    long long perm(int length, int k)
    {
        long long res = 1;

        for (int cnt : alpha) {
            if (cnt == 0) continue;
            res *= comb(length, cnt, k);
            if (res >= k) return k;
            length -= cnt;
        }

        return res;
    }

private:
    vector<int> alpha;
};
// @lc code=end

int main()
{
    Solution s;
    s.smallestPalindrome("aaaaabbbbbbbbbbaaaaa", 251);
    return 0;
}
