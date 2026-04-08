/*
 * @Author: Dragon-qing
 * @Date: 2026-04-08
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\295\solution.cpp
 * @Description: 数据流的中位数, 设计、两个堆
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
static bool DefaultCmp(int a, int b) { return a < b; }

class Heap{
public:
    using Cmp = bool(*)(int, int);

    explicit Heap(Cmp cmp = DefaultCmp) 
    {
        m_pVec = make_unique<vector<int>>();
        m_pCmp = cmp;
    }
    ~Heap(){}

    /**
     * @brief: 获取堆顶元素
     * @return {optional<int>} 失败：返回nullopt 成功：返回堆顶值
     */
    optional<int> Top()
    {
        if (m_pVec->empty())
        {
            return nullopt;
        }

        return m_pVec->front();
    }
    
    /**
     * @brief: 弹出堆顶元素
     * @return {void}
     */
    void Pop()
    {
        if (m_pVec->empty())
        {
            return;
        }

        auto &v = *m_pVec; // 取索引
        swap(v[0], v.back());
        v.pop_back();
        SiftDown(0);
    }
  
    /**
     * @brief: 压入元素
     * @param {int} e: 待压入元素
     * @return {void}
     */
    void Push(int e)
    {
        auto &v = *m_pVec;
        v.push_back(e);
        SiftUp(v.size() - 1);
    }

    /**
     * @brief: 获取当前元素数量
     * @return {int}
     */
    int Size()
    {
        return m_pVec->size();
    }
private:
    unique_ptr<vector<int>> m_pVec;
    Cmp m_pCmp;

    /**
     * @brief: 上浮元素
     * @param {int} index: 索引
     * @return {*}
     */
    void SiftUp(int index)
    {
        auto &v = *m_pVec;
        if (v.size() == 1)
        {
            return;
        }

        int pos = index;
        while (pos > 0)
        {
            int parent = (pos - 1) / 2;
            if (m_pCmp(v[parent], v[pos]))
            {
                swap(v[pos], v[parent]);
                pos = parent;
            }
            else
            {
                break;
            }
        }
        
    }

    /**
     * @brief: 下沉元素
     * @param {int} index: 索引
     * @return {*}
     */
    void SiftDown(int index)
    {
        auto &v = *m_pVec;
        if (v.size() == 1)
        {
            return;
        }

        int n = v.size();

        while(true)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < n && m_pCmp(v[largest], v[left]))
            {
                largest = left;
            }
            if (right < n && m_pCmp(v[largest], v[right]))
            {
                largest = right;
            }

            if (largest == index)
            {
                break;
            }
            swap(v[index], v[largest]);
            index = largest;
        }
    }
};

class MedianFinder {
public:
    MedianFinder() : m_hRight([](int a, int b){return a > b;}) {
        m_nSize = 0;
    }
    
    void addNum(int num) {
        if (m_hRight.Size() > 0)
        {
            if (num > *m_hRight.Top())
            {
                m_hRight.Push(num);
            }
            else
            {
                m_hLeft.Push(num);
            }
        }
        else
        {
            m_hLeft.Push(num);
        }
        m_nSize++;
        if (abs(m_hLeft.Size() - m_hRight.Size()) < 2)
        {
            return;
        }

        // 调整平衡
        if (m_hLeft.Size() > m_hRight.Size())
        {
            int i = *m_hLeft.Top();
            m_hLeft.Pop();
            m_hRight.Push(i);
        }
        else
        {
            int i = *m_hRight.Top();
            m_hRight.Pop();
            m_hLeft.Push(i);
        }
    }
    
    double findMedian() {
        if (m_nSize == 0)
        {
            return 0.0;
        }
        else if(m_nSize == 1)
        {
            return static_cast<double>(*m_hLeft.Top());
        }
        int left = *m_hLeft.Top();
        int right = *m_hRight.Top();
        double res = 0;
        if (m_nSize & 1) // 奇数
        {
            res = m_hLeft.Size() > m_hRight.Size() ? left : right;
        }
        else
        {
            res = ((double)left + right) / 2;
        }

        return res;
    }
private:
    Heap m_hLeft; // 大根堆
    Heap m_hRight; // 小根堆
    int m_nSize;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

int main()
{
    MedianFinder m;
    m.addNum(1);
    m.addNum(2);
    m.addNum(3);
    cout << m.findMedian();
    return 0;
}
