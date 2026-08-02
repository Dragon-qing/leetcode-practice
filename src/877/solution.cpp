/*
 * @Author: Dragon-qing
 * @Date: 2026-08-02
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\877\solution.cpp
 * @Description: 动态规划
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */

// @lc code=start
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector dp(n, vector<int>(n, INT32_MIN));

        // 预先填写Bob拿最后一组的情况
        for (int i = 0; i < n; i++) {
            dp[i][i] = -piles[i];
        }

        int turn = 1;
        int loop = 1;
        while (loop < n) {
            for (int row = 0, col = loop; col < n; row++,col++) {
                int left = dp[row + 1][col] + turn * piles[row];
                int right = dp[row][col - 1] + turn * piles[col];
                dp[row][col] = max(left * turn, right * turn) * turn; // 每个选手选择最优解，记alice为+，Bob为-；
            }
            // 交换选手
            turn *= -1;
            loop++;
        }

        return dp[0][n - 1] > 0;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> piles = {3,7,2,3};
    cout << s.stoneGame(piles);
    return 0;
}
