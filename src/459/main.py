class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        mid_idx = len(s) // 2
        sub_str = ""
        for i in range(mid_idx):
            sub_str += s[i]
            if len(s) % len(sub_str) != 0: # 可以整除
                continue
            tmp_str = sub_str * (len(s) // len(sub_str))
            if tmp_str == s:
                return True

        return False