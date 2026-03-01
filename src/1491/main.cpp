#include <bits/stdc++.h>
#include <ranges>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        std::ranges::sort(salary);
        int sum = 0;
        for (int i = 1; i < salary.size() - 1; i++)
        {
            sum += salary[i];
        }
        
        return sum * 1.0 / (salary.size() - 2); 
    }
};

int main()
{
    Solution s;
    vector<int> vec{4000,3000,1000,2000};
    cout << s.average(vec);
    return 0;
}