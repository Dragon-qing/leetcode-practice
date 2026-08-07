/*
 * @Author: Dragon-qing
 * @Date: 2026-08-07
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3348\solution.cpp
 * @Description: 贪心，数学，字符串
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3348 lang=cpp
 *
 * [3348] 最小可整除数位乘积 II
 */

// @lc code=start
class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long tmp = t;
        int primeNums[] = {2, 3, 5, 7};
        
        // 如果想要符合条件，那质数因子只能是2,3,5,7。
        for (auto i : primeNums) {
            while (tmp % i == 0) {
                tmp /= i;
            }
        }

        if (tmp > 1) {
            return "-1";
        }

        int n = num.length();

        vector<long long> rem(n + 1);
        rem[0] = t;
        int pos = n - 1; // 填数开始位置
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                pos = i;
                break;
            }
            rem[i + 1] = rem[i] / gcd(rem[i], num[i] - '0');
        }

        if (rem[n] == 1) { 
            // num自身可以被t整除
            return num;
        }

        // 按num的位数从右往左开始尝试
        for (int i = pos; i >= 0; i--) {
            while (++num[i] <= '9') {
                long long tNow = rem[i] / gcd(rem[i], num[i] - '0');
                int k = 9;
                for (int j = n - 1; j > i; j--) {
                    while (tNow % k) {
                        k--;
                    }
                    tNow /= k;
                    num[j] = '0' + k;
                }
                if (tNow == 1) {
                    return num;
                }
            }
        }

        // 位数不够，需要贪心尝试更多位数
        string ans;
        for (int i = 9; i > 1; i--) { // 从9开始在最后翻转时能保证最小
            while (t % i == 0) {
                t /= i;
                ans += i + '0';
            }
        }
        // 不够位数就补充1
        ans += string(max(n + 1 - static_cast<int>(ans.length()), 0), '1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

