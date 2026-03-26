/*
 * @Author: Dragon-qing
 * @Date: 2026-03-26
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3548\solution.cpp
 * @Description: 矩阵，前缀和，哈希
 */
#include <bits/stdc++.h>
#include "common.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=3548 lang=cpp
 *
 * [3548] 等和矩阵分割 II
 */

// @lc code=start
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_set<long long> preHash;
        unordered_map<long long, int> nextHash;
        vector<vector<long long>> prefix(m, vector<long long>(n));

        prefix[0][0] = grid[0][0];
        // 构建前缀和矩阵
        for (int i = 1; i < m; i++)
        {
            prefix[i][0] = prefix[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < n; i++)
        {
            prefix[0][i] = prefix[0][i - 1] + grid[0][i];
        }
        for (int r = 1; r < m; r++)
        {
            for (int c = 1; c < n; c++)
            {
                prefix[r][c] = prefix[r-1][c] + prefix[r][c-1] + grid[r][c] - prefix[r-1][c-1];
            }
        }

        long long allSum = prefix[m - 1][n - 1];
        // 水平分割
        for (int r = 0; r < m; r++)
        {
             ranges::for_each(grid[r], [&nextHash](int i){
                    nextHash[i] += 1;
             });
        }
        int cur = 0;
        long long preSum = 0;
        long long removeElement = 0;
        bool result = false;
        while (cur < m - 1)
        {
            // 更新两个hash表
            preHash.insert(grid[cur].begin(), grid[cur].end());
            ranges::for_each(grid[cur], [&nextHash](int i){
                    nextHash[i] -= 1;
            });
            
            preSum = prefix[cur][n - 1];
            removeElement = abs(allSum - 2 * preSum);
            if (preSum * 2 == allSum)
            {
                result = true;
            }
            else if (preSum * 2 > allSum)// 在分割线上半部分寻找可舍弃元素
            {
                if (cur == 0 
                    && (grid[0][0] == removeElement || grid[0][n - 1] == removeElement))
                {
                    
                    result = true;
                }
                else if (preHash.contains(removeElement) && cur != 0)
                {
                    if (n != 1 || removeElement == grid[0][0] || removeElement == grid[cur][0])
                        result = true;

                }
            }
            else// 在分割线下半部分寻找可舍弃元素
            {
                if (cur == m - 2 
                    && (grid[m - 1][0] == removeElement || grid[m - 1][n - 1] == removeElement))
                {
                    result = true;
                }
                else if (nextHash[removeElement] > 0 && cur != m - 2)
                {
                    if (n != 1 || removeElement == grid[cur + 1][0] || removeElement == grid[m-1][0])
                        result = true;
                }
            }
            if (result)
            {
                return result;
            }
            
            cur++;
        }
        // 垂直分割
        preHash.clear();
        nextHash.clear();
        for (int r = 0; r < m; r++)
        {
            ranges::for_each(grid[r], [&nextHash](int i){
                nextHash[i] += 1;
            });
        }
        cur = 0;
        while(cur < n - 1)
        {
            // 更新hash表
            ranges::for_each(grid, [cur, &preHash, &nextHash](const vector<int>& row){
                preHash.insert(row[cur]);
                nextHash[row[cur]] -= 1;
            });
            preSum = prefix[m - 1][cur];
            removeElement = abs(allSum - 2 * preSum);
            if (preSum * 2 == allSum)
            {
                result = true;
            }
            else if (preSum * 2 > allSum)// 在分割线左半部分寻找可舍弃元素
            {
                if (cur == 0 
                    && (grid[0][0] == removeElement || grid[m - 1][0] == removeElement))
                {
                    
                    result = true;
                }
                else if (preHash.contains(removeElement) && cur != 0)
                {
                    if (m != 1 || grid[0][cur] == removeElement || grid[0][0] == removeElement)
                        result = true;
                }
            }
            else// 在分割线右半部分寻找可舍弃元素
            {
                if (cur == n - 2 
                    && (grid[0][n - 1] == removeElement || grid[m - 1][n - 1] == removeElement))
                {
                    result = true;
                }
                else if (nextHash[removeElement] > 0 && cur != n - 2)
                {
                    if (m != 1 || grid[0][cur + 1] == removeElement || grid[0][n - 1] == removeElement)
                        result = true;
                }
            }
            if (result)
            {
                return result;
            }
            cur++;
        }
        return result;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> v = Read2DVectorIntFromFile("..\\..\\test\\data.txt");
    cout << v.size();
    cout << s.canPartitionGrid(v);
    return 0;
}
