/*
 * @Author: Dragon-qing
 * @Date: 2026-03-09
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\344\solution.cpp
 * @Description: 双指针
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
// @lc code=end

