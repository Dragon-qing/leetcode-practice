/*
 * @Author: Dragon-qing
 * @Date: 2026-04-24
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2833\solution.cpp
 * @Description: 距离原点最远的点，贪心
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2833 lang=cpp
 *
 * [2833] 距离原点最远的点
 */

// @lc code=start
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt_R = count(moves.begin(), moves.end(), 'R');
        int cnt_L = count(moves.begin(), moves.end(), 'L');
        int cnt_ = moves.size() - cnt_L - cnt_R;

        return (max(cnt_R, cnt_L) + cnt_ - min(cnt_R, cnt_L));
    }
};
// @lc code=end

