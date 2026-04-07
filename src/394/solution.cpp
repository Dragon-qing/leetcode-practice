/*
 * @Author: Dragon-qing
 * @Date: 2026-04-07
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\394\solution.cpp
 * @Description: 字符串解码, 栈
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        int num = 0;
        string res = "";
        stack<int> nums;
        stack<string> strs;

        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                num = num * 10 + s[i] - '0';
            }
            else if (isalpha(s[i]))
            {
                res += s[i];
            }
            else if (s[i] == '[')
            {
                nums.emplace(num);
                strs.emplace(res);
                num = 0;
                res = "";
            }
            else
            {
                int times = nums.top();
                nums.pop();
                for (auto _ : std::views::iota(0, times))
                {
                    strs.top() += res;
                }
                res = strs.top();
                strs.pop();
            }
        }

        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.decodeString("3[a]2[bc]");
    return 0;
}
