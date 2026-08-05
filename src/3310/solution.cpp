/*
 * @Author: Dragon-qing
 * @Date: 2026-08-05
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3310\solution.cpp
 * @Description: 有向图，DFS
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3310 lang=cpp
 *
 * [3310] 移除可疑的方法
 */

// @lc code=start
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n);

        // 转化为图
        for (auto e : invocations) {
            g[e[0]].push_back(e[1]);
        }

        vector<bool> isBug(n, false);

        // 搜索所有的可疑方法
        DFS(isBug, g, k);

        for (auto e : invocations) {
            if (!isBug[e[0]] && isBug[e[1]]) {
                // 非可疑方法调用了可疑方法
                vector<int> ans(n);
                ranges::iota(ans, 0); 
                return ans;
            }
        }

        vector<int> ans;
        for (int i : views::iota(0, n)) {
            if (!isBug[i]) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }

private:
    void DFS(vector<bool>& isBug, vector<vector<int>> &g, int k)
    {
        isBug[k] = true;
        for (auto e : g[k]) {
            if (!isBug[e]) {
                DFS(isBug, g, e);
            }
        }
    }
};
// @lc code=end

int main()
{
    std::cout << __cplusplus << '\n';
}

