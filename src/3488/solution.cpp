/*
 * @Author: Dragon-qing
 * @Date: 2026-04-16
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3488\solution.cpp
 * @Description: 距离最小相等元素查询,二分查找、哈希
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3488 lang=cpp
 *
 * [3488] 距离最小相等元素查询
 */

// @lc code=start
class Solution {
public:
    /**
     * @brief: 二分查找
     * @param {vector<int>} vec: 数组
     * @param {int} target: 目标值
     * @return {int} 返回索引
     */
    int Search(const vector<int> &vec, int target)
    {
        int n = vec.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (vec[mid] == target) return mid;
            if (target < vec[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return -1;
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        unordered_map<int, vector<int>> hashmap;

        for (int i = 0; i < n; i++)
        {
            hashmap[nums[i]].push_back(i);
        }

        vector<int> answer;

        // 找到对应待查找组
        for (int i = 0; i < m; i++)
        {
            int num = nums[queries[i]];

            auto &vec = hashmap[num];
            int size = vec.size();
            if (size == 1) // 该元素在nums中除自己外没有其他与之相等
            {
                answer.emplace_back(-1);
                continue;
            }
            int idx = Search(vec, queries[i]);

            int rightDis = abs(vec[(idx + 1) % size] - queries[i]);
            rightDis = min(rightDis, n - rightDis); // 将普通情况和边界情况合并

            int leftDis = abs(vec[(idx - 1 + size) % size] - queries[i]);
            leftDis = min(leftDis, n - leftDis);

            answer.emplace_back(min(rightDis, leftDis));
        }

        return answer;
    }
};
// @lc code=end

