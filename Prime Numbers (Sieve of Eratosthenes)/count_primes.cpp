// Write a function to return the total number of prime numbers less than or equal to n

#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n) {
    
    vector<bool> prime(n+1, true);

    int primeCount = 0;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
            prime[i] = false;
        }
    }

    for (int p=2; p <= n; p++) {
        if (prime[p]) {
            primeCount++;
        }
    }

    return primeCount;
}

int main() {
    int n = 100;
    cout << "Number of primes less than or equal to " << n << " is " << countPrimes(n) << endl;
    return 0;
}
