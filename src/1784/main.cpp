#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        if (s.size() == 1)
        {
            return true;
        }

        bool flag = false;
        for(char c : s)
        {
            if ( c == '0')
            {
                flag = true;
            }
            else if (c == '1' && flag == true)
            {
                return false;
            }
        }

        return true;
    }
};
