adj = {}

with open("Day09/input.txt") as f:
    for line in f:
        pair, dist = line.strip().split(" = ", 1)
        first, second = pair.split("to", 1)

        first = first.strip();
        second = second.strip();

        if first not in adj:
            adj[first] = []
        if second not in adj:
            adj[second] = []

        adj[first].append((second, int(dist)))
        adj[second].append((first, int(dist)))

def dfs(curr, visited):
    if len(visited) == len(adj):
        return 0

    ans = 0

    for nxt, dist in adj[curr]:
        if nxt not in visited:
            ans = max(ans, dist + dfs(nxt, visited | {nxt}))

    return ans

ans = 0
for node in adj:
    ans = max(ans, dfs(node, {node}))

print(ans)