class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        if s == "":
            return t

        res_char = str()

        tmp_dict = dict()
        for c in s:
            value = tmp_dict.get(c, 0)
            tmp_dict[c] = value + 1
        for c in t:
            value = tmp_dict.get(c, 0)
            if value == 0:
                res_char = c
                break
            else:
                tmp_dict[c] = value - 1

        return res_char