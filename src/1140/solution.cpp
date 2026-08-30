/*
 * @Author: Dragon-qing
 * @Date: 2026-08-30
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1140\solution.cpp
 * @Description: 记忆化搜索，后缀和
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1140 lang=cpp
 *
 * [1140] 石子游戏 II
 */

// @lc code=start
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        // 计算后缀和
        for (int i = n - 2; i >= 0; i--) {
            piles[i] += piles[i + 1];
        }

        vector memo(n, vector<int>((n + 1) / 4 + 1, -1));

        auto dfs = [&](this auto&& dfs, int i, int m) -> int{
            if (i + 2 * m >= n) {
                return piles[i];
            }

            int &p = memo[i][m];
            if (p != -1) { // 使用记忆化结果
                return p;
            }
            int mn = INT32_MAX;
            for (int pick = 1; pick <= 2 * m; pick++) {
                mn = min(mn, dfs(i + pick, max(m, pick)));
            }

            p = piles[i] - mn;
            return piles[i] - mn;
        };

        return dfs(0, 1);
    }
};
// @lc code=end

int main()
{
    vector<int> piles = {2,7,9,4,4};
    Solution s;
    cout << s.stoneGameII(piles);
    return 0;
}
