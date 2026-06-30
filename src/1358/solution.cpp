/*
 * @Author: Dragon-qing
 * @Date: 2026-06-30
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1358\solution.cpp
 * @Description: 滑动窗口，子字符串
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1358 lang=cpp
 *
 * [1358] 包含所有三种字符的子字符串数目
 */

// @lc code=start
class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, right = 0;
        vector<int> hash(3, 0);

        int ans = 0;
        int cnt = 0;

        while (right < s.size()) {
            int rightIdx = s[right] - 'a'; // 右指针
            if (hash[rightIdx] == 0) {
                cnt += 1;
                if (cnt == 3) { // 包含了“a,b,c”三个
                    ans += s.size() - right; // 累加以s[left, right] 为前缀的所有字符串
                    while (left < right && cnt == 3) { // 缩小窗口
                        hash[s[left] - 'a'] -= 1;
                        if (hash[s[left] - 'a'] == 0) {
                            cnt -= 1;
                        }
                        else {
                            ans += s.size() - right; // 累加所有合规字符串
                        }
                        left++;
                    }
                }
            }
            hash[rightIdx] += 1;
            right++;
        }

        return ans;
    }
};
// @lc code=end

