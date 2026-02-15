from typing import List

class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        max_sum = 0
        for i in accounts:
            max_sum = max(max_sum, sum(i))

        return max_sum