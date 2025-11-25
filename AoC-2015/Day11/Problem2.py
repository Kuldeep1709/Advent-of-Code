with open("Day11/input.txt") as f:
    line = f.readline().strip()

def valid(password):
    for c in password:
        if chr(ord('a') + c) in "ilo": return False
            
    first = third = False
    for i in range(6):
        if password[i+1] == password[i] + 1 and password[i+2] == password[i] + 2:
            first = True
    
    pairs = []
    for i in range(7):
        if password[i] == password[i+1]:
            pairs.append(i)
    
    if len(pairs) > 1 and pairs[-1] - pairs[0] > 1:
        third = True
    
    return first and third

forget = 2
password = [ord(c) - ord('a') for c in line]

while True:
    if (valid(password)): forget -= 1
    if forget == 0: break
    
    idx = 7
    while idx >= 0:
        if password[idx] == 25:
            password[idx] = 0
        else:
            password[idx] += 1
            break
        
        idx -= 1

final_password = ""

for idx in password:
    final_password += chr(ord('a') + idx)

print(final_password)