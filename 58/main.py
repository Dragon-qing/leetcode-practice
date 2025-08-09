class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        processed_str = s.strip()
        start = processed_str.rfind(' ')
        return len(processed_str[start + 1:])