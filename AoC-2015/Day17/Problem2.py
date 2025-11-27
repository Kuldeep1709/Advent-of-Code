containers = []

with open("Day17/input.txt") as f:
    for line in f:
        containers.append(int(line))

dp = dict()
infinite = len(containers) + 1

def total(left, idx):
    if (left, idx) in dp: return dp[(left, idx)]
    if left == 0: return (1, 0)
    if left < 0 or idx == len(containers): return (0, infinite)
    
    ways1, length1 = total(left - containers[idx], idx+1)
    length1 += 1
    ways2, length2 = total(left, idx+1)

    if length1 < length2:
        ans = (ways1, length1)
    elif length2 < length1:
        ans = (ways2, length2)
    else:
        ans = (ways1 + ways2, length1)

    dp[(left, idx)] = ans

    return dp[(left, idx)]
    
ways, min_length = total(150, 0)
print(ways)