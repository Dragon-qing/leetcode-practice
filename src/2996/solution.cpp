/*
 * @Author: Dragon-qing
 * @Date: 2026-08-30
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2996\solution.cpp
 * @Description: 哈希
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2996 lang=cpp
 *
 * [2996] 大于等于顺序前缀和的最小缺失整数
 */

// @lc code=start
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        
        int sum = nums[0];
        int end = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1){
                sum += nums[i];
            } else {
                end = i;
                break;
            }
        }

        unordered_set<int> hash(nums.begin(), nums.end());
        while(hash.contains(sum)) {
            sum++;
        }

        return sum;
    }
};
// @lc code=end

int main()
{
    vector<int> nums = {1,2,3,2,5};
    Solution s;
    cout << s.missingInteger(nums);
    return 0;
}

