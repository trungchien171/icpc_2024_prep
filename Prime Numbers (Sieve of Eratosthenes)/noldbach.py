def generate_primes(n):
    is_prime = [True] * (n+1)
    is_prime[0] = is_prime[1] = False
    primes = []

    for i in range(2, n + 1):
        if is_prime[i]:
            primes.append(i)
            for j in range(i * i, n + 1, i):
                is_prime[j] = False

    return primes

def check_noldbach(n, k):
    primes = generate_primes(n)
    count = 0

    for i in range(len(primes) - 1):
        prime_sum = primes[i] + primes[i + 1] + 1
        if prime_sum <= n and prime_sum in primes:
            count += 1

    if count >= k:
        print("YES")
    else:
        print("NO")

n, k = map(int, input().split())
check_noldbach(n, k)