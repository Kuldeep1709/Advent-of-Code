import json

def total(data):
    if isinstance(data, int):
        return data

    if isinstance(data, list):
        return sum(total(item) for item in data)

    if isinstance(data, dict):
        if "red" in data.values():
            return 0
        return sum(total(v) for v in data.values())

    return 0

with open("Day12/input.txt") as f:
    line = f.readline().strip()

data = json.loads(line)

print(total(data))