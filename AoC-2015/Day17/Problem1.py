containers = []

with open("Day17/input.txt") as f:
    for line in f:
        containers.append(int(line))

dp = dict()

def total(left, idx):
    if (left, idx) in dp: return dp[(left, idx)]
    if left == 0: return 1
    if left < 0 or idx == len(containers): return 0
    
    ans = total(left, idx+1)
    ans += total(left - containers[idx], idx+1)

    dp[(left, idx)] = ans
    return ans
    
print(total(150, 0))