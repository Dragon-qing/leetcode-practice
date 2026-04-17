/*
 * @Author: Dragon-qing
 * @Date: 2026-04-17
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3761\solution.cpp
 * @Description: 镜像对之间最小绝对距离, 哈希表
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3761 lang=cpp
 *
 * [3761] 镜像对之间最小绝对距离
 */

// @lc code=start
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int res = n + 1;

        unordered_map<int, int> hashmap;
        
        for (int i = 0; i < n; i++)
        {
            if (hashmap.contains(nums[i]))
            {
                res = min(res, i - hashmap[nums[i]]);
            }
            hashmap[Reverse(nums[i])] = i;
        }

        return res == n + 1 ? -1 : res;
    }
private:
    int Reverse(int i)
    {
        int res = 0;
        while (i > 0)
        {
            res *= 10;
            res += i % 10;
            i /= 10;
        }

        return res;
    }
};
// @lc code=end



int main()
{
    vector<int> v = {12,21,45,33,54};
    Solution s;
    s.minMirrorPairDistance(v);
    return 0;
}
