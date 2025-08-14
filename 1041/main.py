class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        x_pos = 0
        y_pos = 0
        face_dir = 0
        for ins in instructions:
            if ins == "G":
                if face_dir == 0:
                    y_pos += 1
                elif face_dir == 1:
                    x_pos += 1
                elif face_dir ==2:
                    y_pos -= 1
                elif face_dir == 3:
                    x_pos -= 1
            elif ins == "L":
                face_dir = (face_dir + 4 - 1) % 4
            else:
                face_dir = (face_dir + 1) % 4
        return True if x_pos == 0 and y_pos == 0 or face_dir != 0 else False
