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

def matching(p, v):
    if p == "cats" or p == "trees":
        return int(v) > properties[p]
    elif p == "pomeranians" or p == "goldfish":
        return int(v) < properties[p]
    else:
        return int(v) == properties[p]

with open("Day16/input.txt") as f:
    for line in f:
        match = re.match(pattern, line)
        if match:
            sue, p1, v1, p2, v2, p3, v3 = match.groups()

            if matching(p1, v1) and matching(p2, v2) and matching(p3, v3):
                print("sue number :", sue)