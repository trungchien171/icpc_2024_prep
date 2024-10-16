// find and print all prime numbers within a specified range

#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int n, vector<bool>& isPrime) {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int p = i * i; p <=n; p += i) {
                isPrime[p] = false;
            }
        }
    }
}

void primesInRange(int L, int R) {
    vector<bool> isPrime(R+1, true);
    sieveOfEratosthenes(R, isPrime);

    cout << "Prime numbers in the range [" << L << ", " << R << "]: ";
    for (int i = L; i <= R; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    
    cout << endl;
}

int main() {
    int L = 10;
    int R = 50;
    primesInRange(L, R);
    return 0;
}