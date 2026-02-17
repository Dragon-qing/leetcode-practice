#include <iostream>
#include <vector>
#include <string.h>
#include <bit>
using namespace std;

class Solution {
public:
    int PopCount(int n)
    {
        int count = 0;
        while (n)
        {
            n &= (n-1);
            count += 1;
        }

        return count;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        if (turnedOn > 8) // 边界判断
        {
            return res;
        }
        for (int h = 0; h < 12; h++)
        {
            for (int m = 0; m <= 59; m++)
            {
                if (PopCount(h) + PopCount(m) == turnedOn)
                {
                    char tmpStr[10];
                    memset(tmpStr, 0, sizeof(tmpStr));
                    snprintf(tmpStr, sizeof(tmpStr), "%d:%02d", h, m);
                    res.push_back(string(tmpStr));
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<string> res = s.readBinaryWatch(0);
    for (string &str : res)
    {
        cout << str << endl;
    };
    
    return 0;
}
