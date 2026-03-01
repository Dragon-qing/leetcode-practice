#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int arr[81] = {0}; // 统计A-z字符情况
        int typeCnt = 0;
        int typeAcc = 0;
        int preidx = 0;
        int minLength = INT32_MAX;
        set<int> tragetSet{};
        string res = "";

        for (char c: t)
        {
            if (arr[c - 'A'] == 0)
            {
                typeCnt += 1;
                tragetSet.insert(c - 'A');
            }
            arr[c - 'A'] += 1;
        }

        for (int lastidx = 0; lastidx < (int)s.size(); lastidx++)
        {
            int idx = s[lastidx] - 'A';
            arr[idx] -= 1;

            if (arr[idx] == 0)
            {
                typeAcc += 1;
            }
            while (typeAcc == typeCnt)
            {
                int tmpidx = s[preidx] - 'A';
                if (arr[tmpidx] == 0 && tragetSet.contains(tmpidx))
                {
                    typeAcc -= 1;
                    if (minLength > lastidx - preidx + 1)
                    {
                        minLength = lastidx - preidx + 1;
                        res = s.substr(preidx, lastidx - preidx + 1);
                    }
                }
                arr[tmpidx] += 1;
                preidx++;
            }

            
        }
        return minLength < INT32_MAX ? res : "";
    }
};

int main()
{
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC");
    
    return 0;
}
