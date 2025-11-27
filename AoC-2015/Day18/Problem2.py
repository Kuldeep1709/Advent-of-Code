grid = []
with open("Day18/input.txt") as f:
    for line in f:
        grid.append(line.strip())

M, N, steps = len(grid), len(grid[0]), 100

def inside(x,y):
    return x >= 0 and y >= 0 and x < M and y < N

for _ in range(steps):
    new_grid = []
    for (i, row) in enumerate(grid):
        new_row = ""
        for (j, light) in enumerate(row):
            on = 0
            for (di, dj) in [(0,1), (1,0), (-1, 0), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]:
                if inside(i+di, j+dj) and grid[i+di][j+dj] == '#':
                    on += 1

            if (i, j) in [(0,0), (0, N-1), (M-1, 0), (M-1, N-1)]:
                new_row += '#'
            else:
                if grid[i][j] == '#':
                    if (on == 2 or on == 3): new_row += '#'
                    else: new_row += "."
                else:
                    if (on == 3): new_row += '#'
                    else: new_row += "."

        new_grid.append(new_row)
    
    grid = new_grid

ans = sum(light == '#' for row in grid for light in row)
print(ans)