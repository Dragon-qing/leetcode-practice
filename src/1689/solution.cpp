/*
 * @Author: Dragon-qing
 * @Date: 2026-03-01
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1689\solution.cpp
 * @Description: 贪心，字符串
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char c: n)
        {
            ans = ans > c - '0' ? ans : c - '0';
            if (ans == 9)   // 为9时就没有必要继续遍历了
            {
                break;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.minPartitions("27346209830709182346");
    return 0;
}