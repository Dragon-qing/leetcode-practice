/*
 * @Author: Dragon-qing
 * @Date: 2026-04-20
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2078\solution.cpp
 * @Description: 两栋颜色不同且距离最远的房子， 贪心
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2078 lang=cpp
 *
 * [2078] 两栋颜色不同且距离最远的房子
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        unordered_map<int, int> hashmap;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!hashmap.contains(colors[i]))
            {
                hashmap[colors[i]] = i;
            }
            ans = max(CalMaxDis(i, colors[i], hashmap), ans);
        }

        return ans;
    }

private:
    int CalMaxDis(int idx, int color, const unordered_map<int, int> &hash)
    {
        int ans = 0;
        for (auto item : hash)
        {
            if (item.first == color)
            {
                continue;
            }
            ans = max(idx - item.second, ans);
        }

        return ans;
    }
};
// @lc code=end

class Solution2 {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        if (colors[0] != colors[n - 1]) return n - 1; // 优化，可以不加因为下面循环会计算到
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (colors[i] != colors[0])
            {
                ans = max(ans, max(i, n - 1 - i));
            }
        }

        return ans;
    }
};