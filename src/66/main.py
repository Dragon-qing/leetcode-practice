class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        res_list: List[int] = []
        idx = len(digits) - 1
        flag = True
        while idx >= 0:
            num = digits[idx]
            if num == 9 and flag:
                res_list.insert(0, 0)
            else:
                if flag:
                    res_list.insert(0, num + 1)
                    flag = False
                else:
                    res_list.insert(0, num)
            idx -= 1
        if res_list[0] == 0:
            res_list.insert(0, 1)
        return res_list