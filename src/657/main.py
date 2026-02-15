class Solution:
    def judgeCircle(self, moves: str) -> bool:
        h_point = 0
        v_point = 0
        for c in moves:
            if c == 'R':
                h_point += 1
            elif c == 'L':
                h_point -= 1
            elif c == 'U':
                v_point += 1
            else:
                v_point -=1
        return True if h_point == 0 and v_point == 0 else False