/*
 * @Author: Dragon-qing
 * @Date: 2026-08-28
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3734\solution.cpp
 * @Description: 字符串，贪心，计数
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3734 lang=cpp
 *
 * [3734] 大于目标字符串的最小字典序回文排列
 */

// @lc code=start
class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> nums(26, 0);

        for (auto c : s) {
            nums[c - 'a'] += 1;
        }

        auto valid = [&]() ->bool {
            for (int i : nums) {
                if (i < 0) {
                    return false;
                }
            }
            return true;
        };

        string midStr = "";
        // 检查是否可以构成回文，并且确定中间的字符
        for (int i = 0; i < 26; i++) {
            if (nums[i] % 2 == 0) {
                continue;
            }

            if (!midStr.empty()) {
                return "";
            }
            midStr = 'a' + i;
            nums[i] -= 1;
        }

        int n = target.size();
        for (int i = 0; i < n / 2; i++) {
            nums[target[i] - 'a'] -= 2;
        }

        // 左边一半完全等于target的左半边
        if(valid()) {
            string tmp = target.substr(0, n / 2);
            ranges::reverse(tmp);
            tmp = midStr + tmp; // 构造回文的右半边
            if (tmp > target.substr(n / 2)) {
                return target.substr(0, n / 2) + tmp;
            }
        }

        for (int i = n / 2 - 1; i >= 0; i--) {
            int index = target[i] - 'a';
            nums[index] += 2; // 撤销

            if (!valid()) continue;

            for (int j = index + 1; j < 26; j++) {
                if (nums[j] == 0) continue;
                nums[j] -= 2;
                target.resize(i + 1);
                target[i] = 'a' + j;
                for (int k = 0; k < 26; k++) {
                    target += string(nums[k] / 2, 'a' + k);
                }
                string rightStr = target;
                target += midStr;
                ranges::reverse(rightStr);
                return target + rightStr;
            }
        }

        return "";
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.lexPalindromicPermutation("baba", "abba");
    return 0;
}
