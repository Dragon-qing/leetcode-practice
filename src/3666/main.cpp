/*
 * @Author: Dragon-qing
 * @Date: 2026-02-27
 * @LastEditors: Dragon-qing
 * @LastEditTime: 2026-02-27
 * @FilePath: \leetcode\src\3666\main.cpp
 * @Description: BFS
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        int m = 0;
        int n = s.size();
        vector<set<int>> nodeState(2);
        vector<int> dist(n + 1, INT32_MAX);
        for (int i = 0; i <= n; i++)
        {
            nodeState[i % 2].insert(i);
            if (s[i] == '0' && i < n)
            {
                m++;
            }
        }

        queue<int> q{};
        q.push(m);
        dist[m] = 0;
        nodeState[m % 2].erase(m);

        while(!q.empty())
        {
            m = q.front();
            q.pop();

            int c1 = max(0, k + m - n);
            int c2 = min(m , k);
            int lnode = m + k - 2 * c2;
            int rnode = m + k - 2 * c1;
            auto &nodeSet = nodeState[lnode % 2];
            for (auto itr = nodeSet.lower_bound(lnode); itr != nodeSet.end() && *itr <= rnode;)
            {
                int m2 = *itr;
                q.push(m2);
                dist[m2] = dist[m] + 1;
                itr = next(itr);
                nodeSet.erase(m2);
            }
        }

        return dist[0] < INT32_MAX ? dist[0] : -1;
    }
};

int main()
{
    Solution s;
    cout << s.minOperations("101", 2);
    return 0;
}