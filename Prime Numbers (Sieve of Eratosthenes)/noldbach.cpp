// Nick is interested in prime numbers. Once he read about Goldbach problem. It states that every even integer greater than 2 can be expressed as the sum of two primes. That got Nick's attention and he decided to invent a problem of his own and call it Noldbach problem. Since Nick is interested only in prime numbers, Noldbach problem states that at least k prime numbers from 2 to n inclusively can be expressed as the sum of three integer numbers: two neighboring prime numbers and 1. 
// For example, 19 = 7 + 11 + 1, or 13 = 5 + 7 + 1.
// Two prime numbers are called neighboring if there are no other prime numbers between them.
// You are to help Nick, and find out if he is right or wrong.

// Input
// The first line of the input contains two integers n (2 ≤ n ≤ 1000) and k (0 ≤ k ≤ 1000).

// Output
// Output YES if at least k prime numbers from 2 to n inclusively can be expressed as it was described above. Otherwise output NO.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> generatePrimes(int n) {
    vector<bool> isPrime(n+1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <=n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int p = i * 2; p <= n; p += i) {
                isPrime[p] = false;
            }
        }
    }

    return primes;
}

void checkNoldbach(int n, int k) {
    vector<int> primes = generatePrimes(n);
    int count = 0;

    for (size_t i = 0; i < primes.size() - 1; i++) {
        int sum = primes[i] + primes[i + 1] + 1;
        if (sum <= n) {
            if (find(primes.begin(), primes.end(), sum) != primes.end()) {
                count++;
            }
        }
    }

    if (count >= k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    checkNoldbach(n, k);
    return 0;
}