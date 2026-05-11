/*
 * @Author: Dragon-qing
 * @Date: 2026-05-11
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2553\solution.cpp
 * @Description: 分割数组中数字的数位，数组、模拟
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2553 lang=cpp
 *
 * [2553] 分割数组中数字的数位
 */

// @lc code=start
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        stack<int> st;
        for (int i : nums) {
            while (i > 0) {
                st.push(i % 10);
                i /= 10;
            }
            while (!st.empty()) {
                res.push_back(st.top());
                st.pop();
            }
        }

        return res;
    }
};
// @lc code=end

