/*
 * @Author: Dragon-qing
 * @Date: 2026-08-06
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3345\solution.cpp
 * @Description: 模拟
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3345 lang=cpp
 *
 * [3345] 最小可整除数位乘积 I
 */

// @lc code=start
class Solution {
public:
    int smallestNumber(int n, int t) {
        int tmp = n;
        while (tmp < INT32_MAX) {
            int mul = multiplate(tmp);
            if (mul % t == 0) break;
            tmp++;
        }

        return tmp;
    }
private: 
    int multiplate(int num)
    {
        int ans = 1;
        while (num > 0) {
            int cur = num % 10;
            num /= 10;
            ans *= cur;
            if (ans == 0) break;
        }

        return ans;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.smallestNumber(15, 3);
    return 0;
}
