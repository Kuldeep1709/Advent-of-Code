import re
family = dict()
pattern = r"(\w+) would (gain|lose) (\d+) happiness units by sitting next to (\w+)."

with open("Day13/input.txt") as f:
    for line in f:
        match = re.match(pattern, line)

        if match:
            user1, action, number, user2 = match.groups()

            happiness = int(number)

            if action == "lose":
                happiness = -happiness
            
            if user1 not in family:
                family[user1] = {}

            family[user1][user2] = happiness
            

visited = set()

def optimal(curr, start):
    if len(visited) == len(family)-1: 
        return family[curr][start] + family[start][curr]

    ans = 0
    visited.add(curr)

    for next in family[curr]:
        if next not in visited:
            ans = max(ans, optimal(next, start) + family[curr][next] + family[next][curr])

    visited.remove(curr)

    return ans

start = ""
for member in family:
    start = member
    break

print(optimal(start, start))