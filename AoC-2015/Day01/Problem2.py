with open("input.txt", "r") as f:
    line = f.readline().strip()

ans = 0
pos = 0
for c in line:
    pos += 1
    if c == '(':
        ans += 1
    else:
        ans -= 1

    if ans == -1:
        break

print(pos)
