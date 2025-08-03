def build_next(pattern):
    next_array = [0] * len(pattern)
    j = 0 # 前缀索引
    for i in range(1, len(pattern)):
        while j > 0  and pattern[i] != pattern[j]:
            j = next_array[j-1]
        if pattern[i] == pattern[j]:
            j += 1
        next_array[i] = j
    return next_array

def kmp_match(text, pattern):
    next_array = build_next(pattern)
    match_index = -1
    j = 0
    for i in range(len(text)):
        while j > 0 and text[i] != pattern[j]:
            j = next_array[j-1]
        if text[i] == pattern[j]:
            j += 1
        if j == len(pattern):
            return i - j + 1
    return -1