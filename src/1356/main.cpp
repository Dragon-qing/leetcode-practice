/*
 * @Author: Dragon-qing
 * @Date: 2026-02-25
 * @LastEditors: Dragon-qing
 * @LastEditTime: 2026-02-25
 * @FilePath: \leetcode\src\1356\main.cpp
 * @Description: 排序,popcount
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static int PopCount(int n)
    {
        int count = 0;
        while(n)
        {
            n &= (n - 1);
            count++;
        }

        return count;
    }

    static bool cmp(int a, int b)
    {
        int countA = PopCount(a);
        int countB = PopCount(b);
        if (countA == countB)
        {
            return a < b;
        }
    
        return countA < countB;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);

        return arr;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    vector<int> res = s.sortByBits(arr);
    for (int i : res)
    {
        cout << i << " ";
    }
    
    return 0;
}