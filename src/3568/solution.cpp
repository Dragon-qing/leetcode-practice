/*
 * @Author: Dragon-qing
 * @Date: 2026-09-01
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3568\solution.cpp
 * @Description: BFS, 位运算
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3568 lang=cpp
 *
 * [3568] 清理教室的最少移动
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int startX = 0, startY = 0;
        int trashNum = 0;

        // 给每个垃圾按位编号
        vector<vector<int>> id(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (classroom[i][j] == 'L') {
                    id[i][j] = 1 << trashNum;
                    trashNum++;
                }
            }
        }


        int maxID = 1 << trashNum;
        vector visited(m,vector(n,vector(energy + 1,vector<bool>(maxID, false))));
        visited[startX][startY][energy][0] = true;

        vector<State> q = {{startX, startY, energy, 0}};

        for (int step = 0; !q.empty(); step++) {
            auto tmp = move(q);
            for (auto [x, y, e, mask] : tmp) {
                if (mask == maxID - 1) {
                    // 全部回收完毕
                    return step;
                }
                if (e == 0) {
                    continue;
                }

                for (auto &[dx, dy] : DIRS) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (0 <= nx && nx < m && 0 <= ny && ny < n && classroom[nx][ny] != 'X') {
                        int newE = classroom[nx][ny] == 'R' ? energy : e - 1;
                        int newMask = id[nx][ny] | mask;

                        if (!visited[nx][ny][newE][newMask]) {
                            visited[nx][ny][newE][newMask] = true;
                            q.emplace_back(nx, ny, newE, newMask);
                        }
                    }
                }
            }
        }

        return -1;
    }


private:
    struct State {
        int x;
        int y;
        int e;
        int mask;
    };

    const int DIRS[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
};
// @lc code=end

int main()
{
    vector<string> classroom = {"S.", "XL"};
    int energy = 2;
    Solution s;
    cout << s.minMoves(classroom, energy);
    return 0;
}
