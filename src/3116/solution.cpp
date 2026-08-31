/*
 * @Author: Dragon-qing
 * @Date: 2026-08-31
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3116\solution.cpp
 * @Description: 集合论，二分查找，最小公倍数
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3116 lang=cpp
 *
 * [3116] 单面值组合的第 K 小金额
 */

// @lc code=start
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto check = [&](long long m) -> bool {
            long long cnt = 0;
            for (int i = 1; i < (1 << n); i++) { 
                // 枚举所有非空子集
                long long lcm_res = 1;
                for (int j = 0; j < n; j++) {
                    if (i >> j & 1) {
                        // coins[j] 在集合i中
                        lcm_res = lcm(lcm_res, coins[j]);

                        if (lcm_res > m) break;
                    }
                }
                long long c = m / lcm_res;
                cnt += popcount(1u * i) % 2 ? c : -c;
            }

            return cnt >= k;
        };

        // 二分查找
        long long left = k - 1;
        long long right = 1ll * ranges::max(coins) * k;
        long long mid = 0;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return right;
    }
};
// @lc code=end

