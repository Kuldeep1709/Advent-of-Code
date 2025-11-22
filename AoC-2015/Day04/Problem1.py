import hashlib

with open("Day04/input.txt", "r") as f:
    for line in f:
        line = line.rstrip('\n')
        
        index = 1
        while True:
            key = line + str(index)
            md5Hash = hashlib.md5(key.encode("ascii")).hexdigest()

            if(md5Hash[0:5] == "00000"):
                break
            index += 1
        print(index)
