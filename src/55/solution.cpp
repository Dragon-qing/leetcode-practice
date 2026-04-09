/*
 * @Author: Dragon-qing
 * @Date: 2026-04-09
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\55\solution.cpp
 * @Description: 跳跃游戏，双指针、贪心
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int slow = 0, fast = 1;

        if (n == 1) return true;
        if (nums[0] == 0) return false;

        while (slow < n)
        {
            while (fast < n && nums[fast] != 0) fast++;
            if (fast == n) break;

            if (nums[slow] + slow > fast
                || (nums[slow] + slow == fast && fast == n - 1)) 
            {
                fast++;
            }   
            else
            {
                slow++;
            }

            if (slow == fast) return false;
        }

        return true;
    }
};

// pref:可以不找0的位置，前面的指针每次记录max(right, left + nums[left])
// 最后和nums长度比较即可,return right >= nums.size() - 1;
// @lc code=end

int main()
{
    vector<int> v = {2,0,0};
    Solution s;
    cout << s.canJump(v);
    return 0;
}
