/*
 * @Author: Dragon-qing
 * @Date: 2026-03-31
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3474\solution.cpp
 * @Description: 贪心
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3474 lang=cpp
 *
 * [3474] 字典序最小的生成字符串
 */

// @lc code=start
class Solution
{
public:
    string generateString(string str1, string str2)
    {
        int m = str1.size();
        int n = str2.size();
        string res(m + n - 1, 'a');
        unordered_set<int> fixHash;

        for (int i = 0; i < m; i++)
        {
            if (str1[i] == 'T')
            {
                for (int j = 0; j < n; j++)
                {
                    if (fixHash.contains(i + j) && res[i + j] != str2[j])
                        return ""; // 有冲突
                    else
                    {
                        res[i + j] = str2[j];
                        fixHash.insert(i + j);
                    }
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (str1[i] == 'F')
            {
                bool isNotEqual = false;
                int idx = -1;
                for (int j = i + n - 1; j >= i; j--)
                {
                    if (res[j] != str2[j - i])
                    {
                        if (!isNotEqual)
                            isNotEqual = true;
                    }
                    if (idx == -1 && !fixHash.contains(j))
                    {
                        idx = j;
                    }
                }
                if (isNotEqual) 
                {
                    continue;
                }
                else if(idx != -1)
                {
                    res[idx] = 'b';
                }
                else
                {
                    return "";
                }
            }
        }

        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.generateString("TFTF", "ab");
    return 0;
}
