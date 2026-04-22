/*
 * @Author: Dragon-qing
 * @Date: 2026-04-22
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2452\solution.cpp
 * @Description: 距离字典两次编辑以内的单词，暴力
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2452 lang=cpp
 *
 * [2452] 距离字典两次编辑以内的单词
 */

// @lc code=start
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries[0].size();
        vector<string> res;
        for (auto &q : queries) {
            for(auto &d : dictionary) {
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (q[i] == d[i]) continue;
                    cnt++;
                    if (cnt > 2) break;
                }
                if (cnt <= 2) {
                    res.emplace_back(q);
                    break;
                }
            }
        }

        return res;
    }
};
// @lc code=end

