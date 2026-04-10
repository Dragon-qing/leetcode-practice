/*
 * @Author: Dragon-qing
 * @Date: 2026-04-10
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3740\solution.cpp
 * @Description: 三个相等元素之间的最小距离 I，哈希
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3740 lang=cpp
 *
 * [3740] 三个相等元素之间的最小距离 I
 */

// @lc code=start
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        if (nums.size() < 3) return -1;
        unordered_map<int ,vector<int>> hash;
        int n = nums.size();

        m_nRes = INT32_MAX;
        for (int i : views::iota(0, n))
        {
            hash[nums[i]].emplace_back(i);
        }

        for (auto itr : hash)
        {
            if (itr.second.size() >= 3)
            {
                CalMinTriple(itr.second);
            }
        }

        return m_nRes == INT32_MAX ? -1 : m_nRes;
    }
private:
    int m_nRes; // 结果值

    /**
     * @brief: 计算最小三元组
     * @param {vector<int>} &v: 
     * @return {*}
     */
    void CalMinTriple(const vector<int> &v)
    {
        int minGap = INT32_MAX;

        for (size_t i = 0; i + 2 < v.size(); i++)
        {
            if (v[i + 2] - v[i] < minGap)
            {
                minGap = min(minGap, v[i + 2] - v[i]);
                int sumValue = minGap * 2;
                m_nRes = min(sumValue, m_nRes);
            }
        }
    }
};
// @lc code=end

