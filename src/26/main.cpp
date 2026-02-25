/*
 * @Author: Dragon-qing
 * @Date: 2026-02-25
 * @LastEditors: Dragon-qing
 * @LastEditTime: 2026-02-25
 * @FilePath: \leetcode\src\26\main.cpp
 * @Description: 快慢指针
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t fastidx = 0;
        size_t slowidx = 0;
        set<int> numSet{};
        
        for (fastidx = 0; fastidx < nums.size(); fastidx++)
        {
            int tmp = nums[fastidx];
            if (!numSet.contains(tmp))
            {
                nums[slowidx] = nums[fastidx];
                slowidx++;
            }

            numSet.insert(tmp);
        }

        return slowidx;
    }
};

int main()
{
    vector<int> nums{0,0,1,1,1,2,2,3,3,4};
    Solution s;
    cout << s.removeDuplicates(nums) << endl;
    for (int i: nums)
    {
        cout << i << " ";
    }
    return 0;
}