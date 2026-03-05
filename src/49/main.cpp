#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans{};
        unordered_set<int> visited{};
        for (int i = 0; i < (int)strs.size(); i++)
        {
            if (visited.contains(i)) continue;
            string s = strs[i];
            unordered_set<string>hashset{};
            vector<string> vec{};
            vec.push_back(s);
            ranges::sort(s);
            hashset.emplace(s);
            for (int j = i + 1; j < (int)strs.size(); j++)
            {
                if (visited.contains(j)) continue;
                string s2 = strs[j];
                ranges::sort(s2);
                if (hashset.contains(s2))
                {
                    visited.emplace(j);
                    vec.push_back(strs[j]);
                }
            }
            ans.push_back(vec);
            visited.emplace(i);
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