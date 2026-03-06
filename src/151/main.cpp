#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // 去除多余空格(将要处理的空格集中到s的末尾用resize统一处理)
        int slow = 0, fast = 0;
        while (s[fast] == ' ') fast++;
        for (; fast < (int)s.size(); fast++)
        {
            if (fast - 1 > 0 && s[fast] == s[fast - 1] && s[fast] == ' ') // 处理中间多余的空格
            {
                continue;
            }
            s[slow++] = s[fast];
        }
        if (slow - 1 > 0 && s[slow - 1] == ' ') // 如果末尾有一个多余的空格也要去掉
        {
            s.resize(slow - 1);
        }
        else
        {
            s.resize(slow);
        }
        
        reverse(s.begin(), s.end());
        int start = 0;
        for (int i = 0; i <= (int)s.size(); i++)
        {
            if (s[i] == ' ' || i == s.size())
            {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};

int main()
{
    Solution s;
    cout << s.reverseWords("  hello  world  ");
    return 0;
}
