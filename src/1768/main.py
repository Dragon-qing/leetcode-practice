class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        res_str = ""
        if word1 == "":
            return word2
        elif word2 == "":
            return word1

        min_range = min(len(word1), len(word2))
        for i in range(min_range):
            res_str += (word1[i] + word2[i])

        if min_range < len(word1):
            res_str += word1[min_range:]
        elif min_range < len(word2):
            res_str += word2[min_range:]

        return res_str

if __name__ == '__main__':
    s = Solution()
    print(s.mergeAlternately("abc", "wwwc"))
