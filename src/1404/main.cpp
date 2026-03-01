/*
 * @Author: Dragon-qing
 * @Date: 2026-02-26
 * @LastEditors: Dragon-qing
 * @LastEditTime: 2026-02-26
 * @FilePath: \leetcode\src\1404\main.cpp
 * @Description: 字符串操作
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int stepCnt = 0;
        
        while (s.size() > 1)
        {
            int idx = s.size() - 1;
            if (s[idx] == '0')
            {
                s.pop_back();
                stepCnt += 1;
            }
            else
            {
                size_t pos = s.rfind('0'); // 从右向左找到第一个非1的位置
                if (pos != std::string::npos)
                {
                    int numOfOne = s.size() - pos - 1;
                    s.erase(s.size() - numOfOne);
                    s[s.size() - 1] = '1';
                    stepCnt += (1 + numOfOne);
                }
                else
                {
                    stepCnt += (1 + s.size());
                    s.clear();
                }
            }
        }

        return stepCnt;
    }
};

int main()
{
    Solution s;
    cout << s.numSteps("1011001");
    return 0;
}