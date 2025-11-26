import re
from turtle import position
pattern = r"(\w+) can fly (\d+) km/s for (\d+) seconds, but then must rest for (\d+) seconds."

players = dict()
duration = 2503

with open("Day14/input.txt") as f:
    for line in f:
        match = re.match(pattern, line)

        if match:
            player, speed, time, rest_time = match.groups()
            players[player] = ((int(speed), int(time), int(rest_time)))


curr_scores = dict()
final_scores = dict()

for player in players:
    final_scores[player] = 0
    curr_scores[player] = 0

for d in range(duration):
    for player in players:
        speed, time, rest_time = players[player]
        if (d%(time + rest_time)) < time:
            curr_scores[player] += speed

    max_score = -1
    for player in curr_scores:
        max_score = max(max_score, curr_scores[player])

    for player in curr_scores:
        if curr_scores[player] == max_score:
            final_scores[player] += 1


winner = ""
max_score = 0
for player in final_scores:
    if final_scores[player] > max_score:
        winner = player
        max_score = final_scores[player]

print(winner, max_score)