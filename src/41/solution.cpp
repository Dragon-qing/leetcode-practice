#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            int cur = nums[i];
            if (cur > 0 && cur <= n && cur != i + 1)
            {
                if (nums[cur - 1] != cur)
                {
                    swap(nums[i], nums[cur - 1]);
                }
                else
                {
                    i++;
                }
            }
            else
            {
                i++;
            }
        }
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                ans = i + 1;
                break;
            }
        }
        if (ans == 1 && nums[0] == 1)
        {
            ans = n + 1;
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> vec = {
        1
    };
    s.firstMissingPositive(vec);
    return 0;
}