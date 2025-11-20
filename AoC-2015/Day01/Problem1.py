with open("input.txt", "r") as f:
    line = f.readline().strip()

ans = 0
for c in line:
    if c == '(':
        ans += 1
    else:
        ans -= 1

print(ans)
