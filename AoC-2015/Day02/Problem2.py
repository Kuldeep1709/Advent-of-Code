ans = 0

with open("input.txt", "r") as f:
    for line in f:
        a, b, c = map(int, line.strip().split('x'))    
        ans += (a*b*c) + 2*(a+b+c - max(a,b,c))

print(ans)

