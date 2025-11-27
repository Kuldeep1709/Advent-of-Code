import re
pattern = r"Sue (\d+): (\w+): (\d+), (\w+): (\d+), (\w+): (\d+)"

properties = {
    "children": 3,
    "cats": 7,
    "samoyeds": 2,
    "pomeranians": 3,
    "akitas": 0,
    "vizslas": 0,
    "goldfish": 5,
    "trees": 3,
    "cars": 2,
    "perfumes": 1
}

with open("Day16/input.txt") as f:
    for line in f:
        match = re.match(pattern, line)
        if match:
            sue, p1, v1, p2, v2, p3, v3 = match.groups()
            if properties[p1] == int(v1) and properties[p2] == int(v2) and properties[p3] == int(v3):
                print("sue number :", sue)