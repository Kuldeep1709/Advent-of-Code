with open("Day10/input.txt") as f:
    line = f.readline().strip()

count = 50

while count > 0:
    curr = []
    idx, n = 0, len(line)

    while idx < n:
        length = 1
        while length + idx < n and line[length + idx] == line[idx]:
            length += 1
        
        curr.append(str(length) + line[idx])
        idx += length;
    
    line = "".join(curr)
    count -= 1

print(len(line))