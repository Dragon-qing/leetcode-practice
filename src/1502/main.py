import typing as List

class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        sorted_list = sorted(arr)
        curidx = 1
        preidx = 0
        diff = sorted_list[curidx] - sorted_list[preidx]
        preidx = curidx
        curidx += 1
        while curidx < len(arr):
            if sorted_list[curidx] - sorted_list[preidx] == diff:
                preidx = curidx
                curidx += 1
            else:
                return False
        return True
