/*
 * @Author: Dragon-qing
 * @Date: 2026-03-10
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\438\solution.cpp
 * @Description: 滑动窗口
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size();
        int n = p.size();
        if ( m < n)
        {
            return {};
        }
        unordered_map<char, int> hashmap{};
        vector<int> ans{};
        unordered_map<char, int> curmap{};

        for (int i = 0; i < n; i++)
        {
            hashmap[p[i]] += 1;
            curmap[s[i]] += 1;
        }

        for (int i = 1; i < m; i++)
        {
            if (hashmap == curmap)
            {
                ans.push_back(i - 1);
            }
            int j = i + n - 1;
            if (j >= m)
            {
                curmap.clear();
                break;
            }
            curmap[s[i - 1]] -= 1;
            if (curmap[s[i - 1]] == 0)
            {
                curmap.erase(s[i - 1]);
            }
            curmap[s[j]] += 1;
        }
        if (hashmap == curmap)
        {
            ans.push_back(m - n);
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution s;
    auto res = s.findAnagrams("abab", "ab");
    for (int c : res)
    {
        cout << c << ' ';
    }
    return 0;
}
