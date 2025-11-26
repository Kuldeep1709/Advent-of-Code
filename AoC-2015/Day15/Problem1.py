import re
pattern = r"([A-Za-z]+): capacity (-?\d+), durability (-?\d+), flavor (-?\d+), texture (-?\d+), calories (-?\d+)"

properties = []

with open("Day15/input.txt") as f:
    for line in f:
        match = re.match(pattern, line)
        if match:
            recipe, capacity, durability, flavor, texture, calories = match.groups()
            properties.append((recipe, int(capacity), int(durability), int(flavor), int(texture), int(calories)))

ans = 0

for a in range(101):
    for b in range(101 - a):
        for c in range(101 - a - b):
            d = 100 - a - b - c
            
            p = a*properties[0][1] + b*properties[1][1] + c*properties[2][1] + d*properties[3][1]
            q = a*properties[0][2] + b*properties[1][2] + c*properties[2][2] + d*properties[3][2]
            r = a*properties[0][3] + b*properties[1][3] + c*properties[2][3] + d*properties[3][3]
            s = a*properties[0][4] + b*properties[1][4] + c*properties[2][4] + d*properties[3][4]

            if p < 0 or q < 0 or r < 0 or s < 0: continue

            ans = max(ans, p*q*r*s)

print(ans)