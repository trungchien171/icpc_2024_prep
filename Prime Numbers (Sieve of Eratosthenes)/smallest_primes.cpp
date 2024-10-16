// Write a function to store the smallest prime factor (SPF) of each composite number

#include <iostream>
#include <vector>
using namespace std;

void smallestPrimeFactor(int n) {
    vector<int> spf(n+1);

    for (int i = 1; i <= n; i++) {
        spf[i] = i;
    }

    for (int p = 2; p * p <= n; p++) {
        if (spf[p] == p) {
            for (int i = p * p; i <= n; i += p) {
                if (spf[i] == i) {
                    spf[i] = p;
                }
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << "Smallest prime factor of " << i << " is: " << spf[i] << endl;
    }
}

int main() {
    int n = 30;
    smallestPrimeFactor(n);
    return 0;
}