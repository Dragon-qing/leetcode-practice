#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        int mid = 0;

        if (x == 1)
        {
            return 1;
        }

        if (right > 46340) // 防止溢出
        {
            right = 46341;
        }

        while(left < right)
        {
            mid = (left + right) / 2;
            if (mid * mid > x)
            {
                right = mid;
            }
            else if (mid * mid < x)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        return left - 1;
    }
};

int main()
{
    Solution s;
    std::cout << s.mySqrt(2147395600);
    return 0;
}