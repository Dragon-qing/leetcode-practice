#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hashSet{};
        int sum = PowSum(n);
        while (sum != 1)
        {
            if (hashSet.contains(sum))
            {
                return false;
            }
            hashSet.emplace(sum);
            sum = PowSum(sum);
        }

        return true;
    }
private:
    int PowSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += pow(n % 10, 2);
            n /= 10;
        }

        return sum;
    }
};

int main()
{
    cout << Solution().isHappy(19);
    return 0;
}