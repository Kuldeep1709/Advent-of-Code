with open("Day20/input.txt") as f:
    min_gifts = int(f.readline())

N = 1_000_000
houses = [0] * (N+1)

for elf in range(1, N+1):
    count = 0
    for house in range(elf, N+1, elf):
        houses[house] += 11 * elf
        count += 1
        if count == 50:
            break

        if houses[house] >= min_gifts:
            print(house)
            exit()