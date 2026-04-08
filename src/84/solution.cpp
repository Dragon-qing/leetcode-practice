/*
 * @Author: Dragon-qing
 * @Date: 2026-04-08
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\84\solution.cpp
 * @Description: 柱状图中最大的矩形,哨兵，栈
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() + 2; // 加入两个哨兵
        if (n == 3)
        {
            return heights.back();
        }
        stack<int> st;
        int res = 0;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        st.push(0); // 提前压入开头的哨兵，避免判断
        for (int i = 1; i < n; i++)
        {
            while (heights[st.top()] > heights[i])
            {
                int height = heights[st.top()];
                st.pop();
                int width = i - st.top() - 1; // 可以左右扩散的范围
                res = max(res, height * width);
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> v = {
        2,1,5,6,2,3
    };
    s.largestRectangleArea(v);
    return 0;
}
