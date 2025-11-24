grid = [[0 for _ in range(1000)] for _ in range(1000)]

def parse(line):
    line = line.strip()

    if line.startswith("turn on"):
        op = "on"
        rest = line[len("turn on "):]
    elif line.startswith("turn off"):
        op = "off"
        rest = line[len("turn off "):]
    elif line.startswith("toggle"):
        op = "toggle"
        rest = line[len("toggle "):]
    else:
        raise ValueError("Unknown command")

    start, _, end = rest.partition(" through ")

    x1, y1 = map(int, start.split(','))
    x2, y2 = map(int, end.split(','))

    return op, x1, y1, x2, y2

with open("Day06/input.txt", "r") as f:
    for line in f:
        op, x1, y1, x2, y2 = parse(line)
        
        for i in range(x1, x2+1):
            for j in range(y1, y2+1):
                if op == "off" :
                    grid[i][j] = max(grid[i][j]-1, 0)
                elif op == "on":
                    grid[i][j] += 1
                else:
                    grid[i][j] += 2

ans = sum(sum(row) for row in grid)
print(ans)