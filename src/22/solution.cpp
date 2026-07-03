/*
 * @Author: Dragon-qing
 * @Date: 2026-07-03
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\22\solution.cpp
 * @Description: 回溯
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        BackingTracking(0, 0, n);
        return ans;
    }

private:
    vector<string> ans;
    string tmp;
    static constexpr char chars[2] = {'(', ')'};

    void BackingTracking(int lCnt, int rCnt, int n)
    {
        if (tmp.size() == 2 * n) {
            ans.push_back(tmp);
            return;
        }

        if (lCnt < n) {
            tmp.push_back('(');
            BackingTracking(lCnt + 1, rCnt, n);
            tmp.pop_back();
        }
        if (lCnt > rCnt) {
            tmp.push_back(')');
            BackingTracking(lCnt, rCnt + 1, n);
            tmp.pop_back();
        }
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.generateParenthesis(3);
    return 0;
}
