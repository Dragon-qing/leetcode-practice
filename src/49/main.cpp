/*
 * @Author: dragon-qing
 * @Date: 2026-03-05
 * @LastEditors: dragon-qing
 * @FilePath: \leetcode\src\49\main.cpp
 * @Description: 哈希
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans{};
        unordered_map<string, vector<string>> hashmap{};

        for (string s : strs)
        {
            string sortStr = s;
            ranges::sort(sortStr);
            hashmap[sortStr].emplace_back(s);
        }
        for (auto itr = hashmap.begin(); itr != hashmap.end(); itr++)
        {
            ans.emplace_back(itr->second);
        }
        
        return ans;
    }
};

int main ()
{
    Solution s;
    vector<string> vec = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };
    auto ans = s.groupAnagrams(vec);
    for (auto v : ans)
    {
        for (auto s : v)
        {
            cout << s << ',';
        }
        cout << endl;
    }
    return 0;
}