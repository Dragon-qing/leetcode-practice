/*
 * @Author: Dragon-qing
 * @Date: 2026-03-13
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3296\solution.cpp
 * @Description: 小根堆
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3296 lang=cpp
 *
 * [3296] 移山所需的最少秒数
 */

// @lc code=start
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<tuple<long long, int, long long>, vector<tuple<long long, int, long long>>, greater<>> heap{};
        long long time = 0;
        for (int i : workerTimes)
        {
            heap.push({i, 1, i});
        }
        for (int i = 0 ; i < mountainHeight; i++)
        {
            auto [total, n, base] = heap.top();
            heap.pop();
            total = (1.0 + n) / 2 * n * base;
            time = total;
            heap.push({total + (n + 1ll) * base, n + 1, base});
        }

        return time;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> v = {
        1,5
    };
    cout << s.minNumberOfSeconds(5, v);
    return 0;
}