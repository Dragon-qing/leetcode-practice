from typing import List

class Solution:
    def signFunc(self, product):
        if product > 0:
            return 1
        elif product == 0:
            return 0
        else:
            return -1
    def arraySign(self, nums: List[int]) -> int:
        res = 1
        for i in nums:
            res *= self.signFunc(i)
            if res == 0:
                break
        return res

if __name__ == '__main__':
    s = Solution()
    print(s.arraySign([-1,-2,-3,-4,3,2,1]))
