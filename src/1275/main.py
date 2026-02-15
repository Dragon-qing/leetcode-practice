from typing import List

class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        WIN_PATTERNS = [
            # 行
            [[0, 0], [0, 1], [0, 2]],
            [[1, 0], [1, 1], [1, 2]],
            [[2, 0], [2, 1], [2, 2]],
            # 列
            [[0, 0], [1, 0], [2, 0]],
            [[0, 1], [1, 1], [2, 1]],
            [[0, 2], [1, 2], [2, 2]],
            # 对角线
            [[0, 0], [1, 1], [2, 2]],
            [[0, 2], [1, 1], [2, 0]]
        ]
        a_moves = moves[0::2]
        b_moves = moves[1::2]
        for i in WIN_PATTERNS:
            a_res = 0
            b_res = 0
            for j in i:
                if j in a_moves:
                    a_res += 1
                if j in b_moves:
                    b_res += 1
                if a_res == 3:
                    return "A"
                elif b_res == 3:
                    return "B"

        if len(moves) < 9:
            return "Pending"
        else:
            return "Draw"

if __name__ == '__main__':
    print(Solution().tictactoe([[0,0],[2,0],[1,1],[2,1],[2,2]]))