from typing import List

class Solution:
    def is_int(self, s):
        try:
            int(s)
            return True
        except ValueError:
            return False
    def calPoints(self, operations: List[str]) -> int:
        process_arr = []
        for i in operations:
            cur = len(process_arr) - 1
            if self.is_int(i):
                process_arr.append(int(i))
            elif i == "+":
                process_arr.append(process_arr[cur] + process_arr[cur - 1])
            elif i == "D":
                process_arr.append(2 * process_arr[cur])
            elif i == "C":
                process_arr.pop()
        return sum(process_arr)

if __name__ == '__main__':
    print(Solution().calPoints(["5","-2","4","C","D","9","+","+"]))