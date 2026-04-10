/*
 * @Author: Dragon-qing
 * @Date: 2026-04-10
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\763\solution.cpp
 * @Description: 划分字母区间,贪心
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[26] = {0};
        int left = 0;
        int n = s.size();
        unordered_set<char> hashSet;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            hash[s[i] - 'a'] += 1;
        }

        for (int i = 0; i < n; i++)
        {
            hashSet.insert(s[i]);
            hash[s[i] - 'a'] -= 1;
            if (hash[s[i] - 'a'] == 0)
            {
                hashSet.erase(s[i]);
                if (hashSet.empty())
                {
                    res.push_back(i - left + 1);
                    left = i + 1;
                }
            }
        }

        return res;
    }
};
// @lc code=end

