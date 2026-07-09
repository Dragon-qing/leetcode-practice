/*
 * @Author: Dragon-qing
 * @Date: 2026-07-09
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3532\solution.cpp
 * @Description: 并查集
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3532 lang=cpp
 *
 * [3532] 针对图的路径存在性查询 I
 */

// @lc code=start
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        if (n == 1) {
            return {true};
        }

        // 初始化
        father.resize(n);
        ranges::iota(father, 0);

        for (int i = 1; i < n; i++) {
            if (abs(nums[i] - nums[i - 1]) <= maxDiff) {
                father[i] = i - 1;
            }
        }

        vector<bool> ans;
        for (auto& v : queries) {
            if (UnionFind(v[0]) == UnionFind(v[1])) {
                // 可达
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }

private:
    // 并查集模板
    vector<int> father;
    int UnionFind(int n) {
        return father[n] == n ? n : father[n] = UnionFind(father[n]);
    }
};
// @lc code=end

