/*
 * @Author: Dragon-qing
 * @Date: 2026-08-19
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1386\solution.cpp
 * @Description: 按位运算，哈希表
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1386 lang=cpp
 *
 * [1386] 安排电影院座位
 */

// @lc code=start
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> hash;
        for (auto v : reservedSeats) {
            hash[v[0]] |= 1 << (v[1] - 1);
        }

        // 固定座位顺序数组,把一行每个座位看作一个bit位
        const array<int, 3> SeatNumBit = {0b0000011110, 0b0001111000, 0b0111100000};

        int ans = 2 * n;
        for (auto &[key, value] : hash) {
            
            int reservedBit = value;

            bool canLeft  = (reservedBit & SeatNumBit[0]) == 0;
            bool canMid = (reservedBit & SeatNumBit[1]) == 0;
            bool canRight = (reservedBit & SeatNumBit[2]) == 0;

            if (canLeft && canRight) {
                // 左右都可以，直接放两个
                continue;
            }
            
            if (canLeft || canRight || canMid) {
                // 至少可以放一个
                ans -= 1;
            } else {
                ans -= 2;
            }
        }
        
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> vec = {
        {1,2},{1,3},{1,8},{2,6},{3,1},{3,10}
    };
    cout << s.maxNumberOfFamilies(3, vec);
    return 0;
}
