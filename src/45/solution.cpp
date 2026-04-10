/*
 * @Author: Dragon-qing
 * @Date: 2026-04-09
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\45\solution.cpp
 * @Description: 跳跃游戏 II，贪心、双指针
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int bound = 0, maxPos = 0;
        if (n == 1) return 0;
        int step = 0;
        
        for (int i = 0; i < n - 1; i++)
        {
            maxPos = max(maxPos, i + nums[i]);
            if (i == bound)
            {
                bound = maxPos;
                step++;
            }
        }

        return step;
    }
};
// @lc code=end

int main()
{
    vector<int> v = {5,9,3,2,1,0,2,3,3,1,0,0};
    Solution s;
    cout << s.jump(v);
    return 0;
}
