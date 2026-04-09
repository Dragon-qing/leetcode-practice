/*
 * @Author: Dragon-qing
 * @Date: 2026-04-09
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3655\solution.cpp
 * @Description: 区间乘法查询后的异或 II，暴力、差分数组
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3655 lang=cpp
 *
 * [3655] 区间乘法查询后的异或 II
 */

// @lc code=start
class Solution {
public:
    /**
     * @brief: 快速幂 
     * @param {long long} a: 底数
     * @param {int} n: 指数
     * @return {long long}
     */
    long long FastPow(long long a, int n)
    {
        long long res = 1;
        while (n > 0)
        {
            if (n & 1)
            {
                res = res * a % MOD;
            }
            
            a = (a * a) % MOD;
            n >>= 1;
        }
        return res;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int B = static_cast<int>(sqrt(queries.size()));
        int querNum = queries.size();
        int n = nums.size();
        vector<vector<int>> diffMuls(B);
        for (int i = 0; i < querNum; i++)
        {
            int l = queries[i][0]; // 起点
            int r = queries[i][1]; // 终点
            int k = queries[i][2]; // 步长
            long long v = queries[i][3]; // 乘数

            if (k < B) // 使用差分积
            {
                if (diffMuls[k].empty())
                {
                    diffMuls[k].resize(n + k, 1);
                }
                diffMuls[k][l] = diffMuls[k][l] * v % MOD;
                r = r - (r - l) % k + k;
                diffMuls[k][r] = diffMuls[k][r] * FastPow(v, MOD - 2) % MOD;
            }
            else // 使用暴力
            {
                for (int idx = l; idx <= r; idx += k)
                {
                    nums[idx] = nums[idx] * v % MOD;
                }
            }
        }

        long long diffMul = 1;
        for (int k = 1; k < B; k++)
        {
            if (diffMuls[k].empty())
            {
                continue;
            }
            auto & d = diffMuls[k];
            for (int start = 0; start < k; start++) {
                diffMul = 1;
                for (int i = start; i < n; i += k) {
                    diffMul = diffMul * d[i] % MOD;
                    nums[i] = nums[i] * diffMul % MOD;
                }
            }
        }

        return reduce(nums.begin(), nums.end(), 0, bit_xor());
    }
private:
    const int MOD = 1e9 + 7;
};
// @lc code=end

int main()
{
    vector<int> nums = {1, 1, 1};
    vector<vector<int>> queries = {
        {0,2,1,4}
    };
    Solution s;
    cout << s.xorAfterQueries(nums, queries);
    return 0;
}
