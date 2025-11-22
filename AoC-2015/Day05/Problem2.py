nice = 0
with open("Day05/input.txt", "r") as f:
    for line in f:
        n = len(line)
        alter = twice = False
        seen = dict()

        for (i,c) in enumerate(line):
            if i+1 < n:
                curr = line[i:i+2]
                if curr in seen:
                    if i - seen[curr] > 1:
                        twice = True
                else:
                    seen[curr] = i

            if i+2 < n and line[i+2] == c:
                alter = True
        
        if(alter == True and twice == True):
            nice += 1

print(nice)