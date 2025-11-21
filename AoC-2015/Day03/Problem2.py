with open("input.txt", "r") as f:
    line = f.readline().strip()

ans = 1
santa = False
seen = {(0,0)}
sx,sy,rx,ry = 0,0,0,0

for c in line:
    x, y = (sx, sy) if santa else (rx, ry)

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
    
    if santa:
        sx, sy = x, y
    else:
        rx, ry = x, y

    santa = not santa
    
print(ans)