from typing import List

class Solution:
    def signJudge(self, num: int):
        if num < 0:
            return -1
        elif num == 0:
            return 0
        else:
            return 1
    def isMonotonic(self, nums: List[int]) -> bool:
        if len(nums) <= 2:
            return True
        flag = self.signJudge(nums[1] - nums[0]) # 1单调递增，-1单调递减
        fix = 2 if flag == 0 else flag
        for i in range(2, len(nums)):
            tmp = self.signJudge(nums[i] - nums[i - 1])
            if fix == 2 and tmp != 0:
                fix = tmp
            if tmp * flag == -1 or fix * tmp == -1:
                return False
            flag = tmp
        return True

if __name__ == '__main__':
    s = Solution()
    print(s.isMonotonic([1,1,0]))