/*
 * @Author: Dragon-qing
 * @Date: 2026-03-08
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1980\main.cpp
 * @Description: 哈希，字符串
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        const int n = nums.size();
        unordered_set<string> hashset(nums.begin(), nums.end());
        
        int maxValue = (1<<n) - 1;
        string ans = "";
        for (int i = 0; i <= maxValue; i++)
        {
            ans = bitset<16>(maxValue - i).to_string();
            ans = ans.substr(16 - n); // 去前置0；
            if (!hashset.contains(ans))
            {
                return ans;
            }
        }

        return "";
    }
};

int main()
{
    Solution s;
    vector<string> nums = 
    {
        "1"
    };
    cout << s.findDifferentBinaryString(nums);
    return 0;
}