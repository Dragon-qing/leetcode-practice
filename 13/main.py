class Solution:
    def romanToInt(self, s: str) -> int:
        roman_dict = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }
        i_dict = {
            "V": 4,
            "X": 9
        }
        x_dict = {
            'L': 40,
            'C': 90
        }
        c_dict = {
            'D': 400,
            'M': 900
        }

        idx = 0
        res = 0
        length = len(s)
        while idx < len(s):
            char = s[idx]

            if char == 'I' and idx + 1 < length and s[idx + 1] in i_dict:
                res += i_dict.get(s[idx + 1])
                idx += 1
            elif char == 'X' and idx + 1 < length and s[idx + 1] in x_dict:
                res += x_dict.get(s[idx + 1])
                idx += 1
            elif char == 'C' and idx + 1 < length and s[idx + 1] in c_dict:
                res += c_dict.get(s[idx + 1])
                idx += 1
            else:
                res += roman_dict.get(s[idx])
            idx += 1

        return res