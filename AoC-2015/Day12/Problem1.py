import re

with open("Day12/input.txt") as f:
    line = f.readline().strip()

arr = re.findall(r'-?\d+\.?\d*', line)

print(sum(int(c) for c in arr))