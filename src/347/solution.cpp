/*
 * @Author: Dragon-qing
 * @Date: 2026-03-18
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\347\solution.cpp
 * @Description: 队列
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start

class MyCompare
{
public:
    bool operator()(pair<int, int> a, pair<int, int>b)
    {
        return a.second > b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int ,int>, vector<pair<int, int>>, MyCompare> pri_q;
        unordered_map<int, int> hashMap;
        for (int i : nums)
        {
            hashMap[i] += 1;
        }
        for (auto itr = hashMap.begin(); itr != hashMap.end(); itr++)
        {
            pri_q.push(*itr);
            if (pri_q.size() > k)
            {
                pri_q.pop();
            }
        }
        vector<int> ans(k);
        for (int i = k - 1; i >= 0; i--)
        {
            ans[i] = pri_q.top().first;
            pri_q.pop();
        }

        return ans;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> v = {
        1,1,1,2,2,3
    };
    s.topKFrequent(v, 2);
    return 0;
}
