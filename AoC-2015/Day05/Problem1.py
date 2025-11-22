nice = 0
with open("Day05/input.txt", "r") as f:
    for line in f:
        n = len(line)
        vowels = 0
        twice = False
        naughty = False

        for (i,c) in enumerate(line):
            if c in "aeiou":
                vowels += 1
            if i+1 < n and line[i+1] == c:
                twice = True
            
            next = line[i:i+2]
            if next in ["ab", "cd", "pq", "xy"]:
                naughty = True
                break;
        
        if(not naughty and vowels >= 3 and twice == True):
            nice += 1


print(nice)

