with open("Day10/input.txt") as f:
    line = f.readline().strip()

count = 40

while count > 0:
    newline = ""
    idx, n = 0, len(line)

    while idx < n:
        length = 1
        while length + idx < n and line[length + idx] == line[idx]:
            length += 1
        
        newline += str(length)
        newline += line[idx]
        idx += length;

    line = newline
    count -= 1

print(len(line))