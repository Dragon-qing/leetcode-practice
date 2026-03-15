/*
 * @Author: Dragon-qing
 * @Date: 2026-03-15
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1622\solution.cpp
 * @Description: 设计、线段树、乘法逆元
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1622 lang=cpp
 *
 * [1622] 奇妙序列
 */

// @lc code=start
class Fancy {
public:
    Fancy() {
        m_vData.clear();
        m_nCoef = 1;
        m_nConstantTerm = 0;
    }
    
    void append(int val) {
        int inv_a = QuickPow(m_nCoef, MOD - 2);
        int newVal = ((long long)val - m_nConstantTerm + MOD) * inv_a %MOD;
        m_vData.push_back(newVal);
    }
    
    void addAll(int inc) {
        m_nConstantTerm = (m_nConstantTerm + inc) % MOD;
    }
    
    void multAll(int m) {
        m_nCoef = ((long long)m_nCoef * m) % MOD;
        m_nConstantTerm = ((long long)m_nConstantTerm * m) % MOD;
    }
    
    int getIndex(int idx) {
        if (idx < 0 || idx >= (int)m_vData.size())
        {
            return -1;
        }
        return ((long long)m_vData[idx] * m_nCoef + m_nConstantTerm) % MOD;
    }
private:
    vector<int> m_vData;
    int m_nCoef;
    int m_nConstantTerm;
    const int MOD = 1e9 + 7;

    /**
     * @brief: 快速幂
     * @param {int} x 底数
     * @param {int} n 指数
     * @return {int} 结果MOD 1e9+7
     */
    int QuickPow(int x, int n)
    {
        int ans = 1;
        int cur = x;
        while (n)
        {
            if (n & 1)
            {
                ans = (long long)ans * cur % MOD;
            }
            cur = (long long)cur * cur % MOD;
            n >>= 1;
        }
        return ans;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
// @lc code=end

// 转化为ax+b的格式简化流程

int main()
{
    Fancy a;
    a.append(2);

}