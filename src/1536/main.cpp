/*
 * @Author: Dragon-qing
 * @Date: 2026-03-02
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1536\main.cpp
 * @Description: 贪心算法，矩阵
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        int *zeroArr = new int[n + 1]{0}; // 下标表示有多少个0，元素值表示有多少行
        list<int> zeroList{};
        int step = 0;   // 步数
        
        for (int i = 0; i < n; i++)
        {
            int zeroAcc = 0;
            for (int j = n - 1; j >= 0 ;j--)
            {
                if (grid[i][j])
                {
                    break;
                }
                zeroAcc++;
            }
            zeroArr[zeroAcc] += 1;
            zeroList.push_back(zeroAcc);
        }
        
        // 检验是否可以满足要求
        int count = 0;
        for (int i = n; i >= 0; i--)
        {
            int tmp = zeroArr[i];
            if (tmp != 0)
            {
                count += tmp - 1;
            }
            else
            {
                count--;
            }
            if (i == n) // 有n行，但是数组有n+1个元素，需要的标准是0...n-1，所以下标为n的特殊处理
            {
                count += 1;
            }

            if (count < 0)
            {
                return -1;
            }
        }

        // 计算总步数
        int loop = n - 1;
        while (loop)
        {
            auto itr = find_if(zeroList.begin(), zeroList.end(), [loop](int x){return x >= loop;});
            step += distance(zeroList.begin(), itr);
            if (itr != zeroList.end())
                zeroList.erase(itr);
            
            loop--;
        }
        return step;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {0,0,1},{1,1,0},{1,0,0}
    };
    Solution s;
    cout << s.minSwaps(grid);

    return 0;
}