// Write a function to return the sum of all prime numbers less than or equal to n

#include <iostream>
#include <vector>
using namespace std;

int sumPrimes(int n) {
    vector<bool> prime(n+1, true);

    int sumPrimes = 0;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            sumPrimes += p;
        }
    }

    return sumPrimes;
}

int main() {
    int n = 100;
    cout << "Sum of primes that less than or equal to " << n << " is: " << sumPrimes(n) << endl;
    return 0;
}