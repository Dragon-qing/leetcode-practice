/*
 * @Author: Dragon-qing
 * @Date: 2026-07-06
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\79\solution.cpp
 * @Description: 回溯
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {

    int m = board.size();
    int n = board[0].size();
    visited.resize(m, vector<bool>(n, false));

    bool flag = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            flag = BackTracking(i, j, 0, word, board);
            if (flag) {
                return true;
            }
        }
    }

    return false;
  }

    bool BackTracking(int row, int col, int n, string &word, vector<vector<char>> &board) {

        if (board[row][col] != word[n]) return false;
        if (n == word.size()) return true;

        bool ans = false;
        visited[row][col] = true;
        for (auto &[dx, dy] : dirs) {
            int newX = row + dx;
            int newY = col + dy;
            if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size()) {
                if (visited[newX][newY]) {continue;}
                ans = BackTracking(newX, newY, n + 1, word, board);
                if (ans) break;
            }
        }
        visited[row][col] = false;
        return ans;
    }

private:
  static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  vector<vector<bool>> visited;
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    s.exist(board, "ABCCED");
    return 0;
}
