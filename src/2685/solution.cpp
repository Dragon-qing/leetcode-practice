/*
 * @Author: Dragon-qing
 * @Date: 2026-07-11
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2685\solution.cpp
 * @Description: 并查集
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2685 lang=cpp
 *
 * [2685] 统计完全连通分量的数量
 */

// @lc code=start
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        fa.resize(n);
        rank.resize(n, 1);
        ranges::iota(fa, 0);
        for (auto &edge : edges) {
            UnionSet(edge[0], edge[1]);
        }

        vector<int> numV(n, 0);
        vector<int> numE(n, 0);
        for (int i = 0; i < n; i++) {
            numV[find(i)] += 1;
        }
        for (auto &edge : edges) {
            numE[find(edge[0])] += 1;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == find(i)) {
                if (numE[i] == numV[i] * (numV[i] - 1) / 2) { // 判断是否符合完全连通分量
                    ans += 1;
                }
            }
        }

        return ans;
    }
private:
    // 并查集
    vector<int> fa;
    vector<int> rank; // 不是准确的树高，而是一个大概值
    int find(int n) {
        return fa[n] == n ? n : fa[n] = find(fa[n]); 
    }

    /**
     * @brief: 合并
     * @param {int} x: 
     * @param {int} y: 
     * @return {void}
     */
    void UnionSet(int x, int y) {
        int a = find(x);
        int b = find(y);

        if (a == b) {
            return;
        }

        if (rank[a] > rank[b]) {
            fa[b] = a;
        } else if (rank[a] < rank[b]) {
            fa[a] = b;
        } else {
            fa[b] = a;
            rank[a]++;
        }
    }
};
// @lc code=end

