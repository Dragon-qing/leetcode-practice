class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        tmp_dict = dict()
        s_asc = 0
        t_asc = 0
        for x in s:
            tmp_dict[x] = tmp_dict.get(x, 0) + 1
            s_asc += ord(x)
        for y in t:
            count = tmp_dict.get(y, -1)
            if count == -1:
                return False
            else:
                tmp_dict[y] = count - 1
            t_asc += ord(y)
        if s_asc != t_asc:
            return False

        return True
