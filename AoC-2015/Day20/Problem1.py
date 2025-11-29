with open("Day20/input.txt") as f:
    min_gifts = int(f.readline())

n = 1_000_000
s = [1]*(n+1)
s[0] = s[1] = 0

for i in range(2,int(n**0.5)+1):
    if s[i]:
        s[i*i:n+1:i] = [0]*((n-i*i)//i+1)
primes = [i for i in range(n+1) if s[i]]

gifts, house = 10, 1

while gifts < min_gifts:
    house += 1
    sigma, idx, num = 1, 0, house

    while idx < len(primes) and primes[idx] * primes[idx] <= num:
        count = 0
        while num % primes[idx] == 0:
            count += 1
            num //= primes[idx]

        if count > 0:
            sigma *= (primes[idx]**(count+1) - 1) // (primes[idx]-1)

        idx += 1

    if num > 1:
        sigma *= (num + 1)

    gifts = 10 * sigma

print(house)