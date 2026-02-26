/*
 * @Author: Dragon-qing
 * @Date: 2026-02-26
 * @LastEditors: Dragon-qing
 * @LastEditTime: 2026-02-26
 * @FilePath: \leetcode\src\904\main.cpp
 * @Description: 滑动窗口
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int sum = 0;
        int preidx = 0;
        int result = 0;
        int typeCnt = 0;
        set<int> fruitsType{};
        map<int, int> fruitsMap{};

        for (int lastidx = 0; lastidx < (int)fruits.size(); lastidx++)
        {
            int type = fruits[lastidx];
            fruitsMap[type] += 1;
            if (typeCnt < 2 && !fruitsType.contains(type))
            {
                fruitsType.insert(type);
                typeCnt += 1;
            }
            if (fruitsType.contains(type))
            {
                sum += 1;
                result = result < sum ? sum : result;
            }
            while (typeCnt >= 2 && !fruitsType.contains(type))
            {
                int tmp = fruits[preidx];
                fruitsMap[tmp] -= 1;
                sum -= 1;
                preidx++;
                if (fruitsMap[tmp] == 0)
                {
                    fruitsType.erase(tmp);
                    sum += 1; // lastidx位置的水果加入总数中，否则
                    fruitsType.insert(fruits[lastidx]);
                    break;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> fruits {0,1,2,2};
    cout << s.totalFruit(fruits);
    return 0;
}