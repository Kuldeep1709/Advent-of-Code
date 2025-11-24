newtotal = total = 0

with open("Day08/input.txt") as f:
    for line in f:
        line = line.strip()
        total += len(line)
        newtotal += len(line) + line.count('\\') + line.count('"') + 2;

print(newtotal - total)