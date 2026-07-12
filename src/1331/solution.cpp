/*
 * @Author: Dragon-qing
 * @Date: 2026-07-12
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1331\solution.cpp
 * @Description: 排序，哈希
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 *
 * [1331] 数组序号转换
 */

// @lc code=start
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};
        vector<int> tmp = arr;
        ranges::sort(tmp);
        unordered_map<int, int> hash;

        int prev = tmp.front();
        int index = 1;
        for (int i : tmp) {
            if (prev != i) {
                index += 1;
            }
            hash[i] = index;
            prev = i;
        }

        vector<int> ans(arr.size(), 0);
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = hash[arr[i]];
        }

        return ans;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> arr = {40,10,20,30};
    s.arrayRankTransform(arr);
    return 0;
}
