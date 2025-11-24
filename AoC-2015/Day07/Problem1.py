with open("Day07/input.txt") as f:
    instructions = {}
    for line in f:
        expr, wire = line.strip().split(" -> ")
        instructions[wire] = expr

signals = {}

def get(wire):
    if wire.isdigit():
        return int(wire)
    if wire in signals:
        return signals[wire]

    parts = instructions[wire].split()

    if len(parts) == 1:
        val = get(parts[0])
    elif len(parts) == 2:
        val = ~get(parts[1]) & 0xFFFF
    else:
        a, op, b = parts
        if op == "AND":
            val = get(a) & get(b)
        elif op == "OR":
            val = get(a) | get(b)
        elif op == "LSHIFT":
            val = get(a) << int(b)
        elif op == "RSHIFT":
            val = get(a) >> int(b)

    signals[wire] = val
    return val

print(get("a"))