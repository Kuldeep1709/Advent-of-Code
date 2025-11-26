import re
pattern = r"(\w+) can fly (\d+) km/s for (\d+) seconds, but then must rest for (\d+) seconds."

players = []
duration = 2503

with open("Day14/input.txt") as f:
    for line in f:
        match = re.match(pattern, line)

        if match:
            player, speed, time, rest_time = match.groups()

            speed, time, rest_time = int(speed), int(time), int(rest_time)
            
            run_time = (duration//(time + rest_time))*time
            run_time += min(duration%(time + rest_time), time)

            score = run_time*speed

            players.append((player, score))

winner = ""
max_score = 0
for (player, score) in players:
    if score > max_score:
        winner = player
        max_score = score

print(winner, max_score)