/*
 * @Author: Dragon-qing
 * @Date: 2026-04-07
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2069\solution.cpp
 * @Description: 模拟行走机器人 II, 模拟、矩阵
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2069 lang=cpp
 *
 * [2069] 模拟行走机器人 II
 */

// @lc code=start
class Robot {
public:
    enum Robot_Dir{
        EAST = 0,
        NORTH,
        WEST,
        SOUTH,

        DIR_NUM
    };
    Robot(int width, int height) {
        m_nDir = EAST;
        m_nMod = (width + height) * 2 - 4;
        m_nWidth = width;
        m_nHeight = height;
        m_vCurPos.assign(2, 0);
    }
    
    void step(int num) {
        num %= m_nMod;
        if (num == 0 && m_vCurPos[0] == 0 && m_vCurPos[1] == 0) // 初始点如果跑整圈时，需要改变方向
        {
            m_nDir = SOUTH;
        }
        for (int i = 0; i < num; i++)
        {
            if (m_vCurPos[0] + DIRS[m_nDir][0] < 0 || 
                m_vCurPos[0] + DIRS[m_nDir][0] >= m_nWidth ||
                m_vCurPos[1] + DIRS[m_nDir][1] < 0 ||
                m_vCurPos[1] + DIRS[m_nDir][1] >= m_nHeight)
            {
                m_nDir = static_cast<Robot_Dir>((m_nDir + 1) % DIR_NUM);
            }
            m_vCurPos[0] += DIRS[m_nDir][0];
            m_vCurPos[1] += DIRS[m_nDir][1];
        }
    }
    
    vector<int> getPos() {
        return m_vCurPos;
    }
    
    string getDir() {
        string str = "";
        switch (m_nDir)
        {
        case EAST:
            str = "East";
            break;
        case SOUTH:
            str = "South";
            break;
        case WEST:
            str = "West";
            break;
        case NORTH:
            str = "North";
            break;
        default:
            break;
        }
        return str;
    }
private:
    Robot_Dir m_nDir; // 记录方向
    int m_nMod; // 模数
    int m_nWidth;
    int m_nHeight;
    vector<int> m_vCurPos; // 当前坐标
    static constexpr array<array<int, 2>, 4> DIRS = {{
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
}}; // 前进表
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
// @lc code=end

