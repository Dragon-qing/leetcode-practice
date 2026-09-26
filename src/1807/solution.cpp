/*
 * @Author: Dragon-qing
 * @Date: 2026-09-26
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1807\solution.cpp
 * @Description: 哈希
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1807 lang=cpp
 *
 * [1807] 替换字符串中的括号内容
 */

// @lc code=start
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dic;
        for (auto &v : knowledge) {
            dic[v[0]] = v[1];
        }
        int begin = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                begin = i;
                end = i + 1;
                string key = "";
                while (s[end] != ')') {
                    key += s[end];
                    end++;
                }
                string value = "?";
                if (dic.contains(key)) {
                    value = dic[key];
                }
                s.replace(begin, end - begin + 1, value);
            }
        }

        return s;
    }
};
// @lc code=end

