with open("input.txt", "r") as f:
    line = f.readline().strip()

ans = 1
seen = {(0,0)}
x,y = 0,0

for c in line:
    if c == '^':
        y += 1
    elif c == '>':
        x += 1
    elif c == 'v':
        y -= 1
    elif c == '<':
        x -= 1

    if (x,y) not in seen:
        ans += 1
        seen.add((x,y))
    
print(ans)

