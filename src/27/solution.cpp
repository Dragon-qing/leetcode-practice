/*
 * @Author: Dragon-qing
 * @Date: 2026-03-09
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\27\solution.cpp
 * @Description: 双指针
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0;
        int n = nums.size();
        for (; fast < n; fast++)
        {
            if (nums[fast] != val)
            {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> vec = {2,2,3};
    cout << s.removeElement(vec, 2);
    return 0;
}