formula = ""
replacements = dict()

with open("Day19/input.txt") as f:
    for line in f:
        if "=>" not in line:
            formula += line.strip()
        else:
            a, b = line.split("=>", 1)
            a, b = a.strip(), b.strip()
            if a in replacements:
                replacements[a].append(b)
            else:
                replacements[a] = [b]

n = len(formula)
molecules = set()

def form_new_molecule(curr, idx, length):
    if curr in replacements.keys():
        for next in replacements[curr]:
            new_formula = formula[0:idx]
            new_formula += next
            new_formula += formula[idx+length:]

            molecules.add(new_formula)

for i in range(n):
    curr = formula[i]
    form_new_molecule(curr, i, 1)
    
    if i+1 < n:
        curr += formula[i+1]
        form_new_molecule(curr, i, 2)

print(len(molecules))