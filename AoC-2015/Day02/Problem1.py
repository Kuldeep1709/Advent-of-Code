ans = 0

with open("input.txt", "r") as f:
    for line in f:
        a, b, c = map(int, line.strip().split('x'))    
        ans += 2*((a*b) + (b*c) + (c*a)) + min(a*b, b*c, c*a)

print(ans)

