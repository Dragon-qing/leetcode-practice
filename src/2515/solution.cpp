/*
 * @Author: Dragon-qing
 * @Date: 2026-04-15
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2515\solution.cpp
 * @Description: 到目标字符串的最短距离, 数组，字符串
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2515 lang=cpp
 *
 * [2515] 到目标字符串的最短距离
 */

// @lc code=start
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int res = INT32_MAX;
        int n = words.size();
        int left = startIndex;
        int right = (startIndex + 1) % n;
        int step = 0;
        while (left != (startIndex + 1) % n)
        {
            if (words[left] == target)
            {
                res = min(step, res);
                break;
            }
            left = (left - 1 + n) % n;
            step += 1;
        }

        step = 1;
        while (right != startIndex)
        {
            if (words[right] == target)
            {
                res = min(res, step);
                break;
            }
            right = (right + 1) % n;
            step += 1;
        }

        return res == INT32_MAX ? -1 : res;
    }
};
// @lc code=end

int main()
{
    vector<string> v = {"fwyzdhjqwn","swgfvpxmky","miiylnccum","swgfvpxmky","odsiosadwj","pslegdboxh","odsiosadwj","pslegdboxh","odsiosadwj","bjnsofzsjg"};

    Solution s;
    s.closestTarget(v, "cbjinsoapx", 9);
    return 0;
}
