/*
 * @Author: Dragon-qing
 * @Date: 2026-02-19
 * @LastEditors: Dragon-qing
 * @LastEditTime: 2026-02-19
 * @FilePath: \leetcode\src\696\main.cpp
 * @Description: 
 */
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 0;
        char c = s.at(0);
        vector<int> compressVec;
        int tmp = 0;
        
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (c == s.at(i))
            {
                tmp++;
            }
            else
            {
                compressVec.push_back(tmp);
                tmp = 1;
            }

            c = s.at(i);
        }
        compressVec.push_back(tmp);
        for (int i = 1; i < (int)compressVec.size(); i++)
        {
            count += min(compressVec[i], compressVec[i-1]);
        }

        return count;
    }
};

int main()
{
    Solution s;
    cout << s.countBinarySubstrings("00110011");

    return 0;
}