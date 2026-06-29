/*
 * @Author: Dragon-qing
 * @Date: 2026-06-29
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1967\solution.cpp
 * @Description: 字符串匹配，kmp
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1967 lang=cpp
 *
 * [1967] 作为子字符串出现在单词中的字符串数目
 */

// @lc code=start
class Solution {
public:
    vector<int> BuildNext(string pattern) {
        vector<int> next(pattern.size());

        int j = -1;
        next[0] = j;
        for (int i = 1; i < pattern.size(); i++) {
            while (j >= 0 && pattern[i] != pattern[j + 1]) {
                j = next[j];
            }
            if (pattern[i] == pattern[j + 1]) {
                j++;
            }
            next[i] = j;
        }

        return next;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (string s : patterns) {
            vector<int> next = BuildNext(s);
            int j = -1;
            for (int i = 0; i < word.size(); i++) {
                while (j >= 0 && s[j + 1] != word[i]) {
                    j = next[j];
                }
                if (s[j + 1] == word[i]) {
                    j++;
                }
                if (j + 1 == s.size()){
                    ans += 1;
                    break;
                }
            }
        }   

        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> patterns = {"a","abc","bc","d"};
    cout << s.numOfStrings(patterns, "abc");
    return 0;
}

// @lc code=end

