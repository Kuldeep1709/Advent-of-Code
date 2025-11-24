total = in_memory = 0

def count(line):
    ans, n, i = 0, len(line) - 1, 1

    while i < n:
        if line[i] != '\\':
            ans += 1
            i += 1
        else:
            if line[i+1] == 'x':
                ans += 1
                i += 4
            else:
                ans += 1
                i += 2
    return ans


with open("Day08/input.txt") as f:
    for line in f:
        line = line.strip()
        total += len(line)
        in_memory += count(line)
    
print(total - in_memory)