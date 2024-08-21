#include <iostream>
using namespace std;

#define MOD 1000000007

long long int binary_exponentiation(long long int a, long long int b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a % MOD;
    }
    long long int half = (binary_exponentiation(a, b / 2) * binary_exponentiation(a, b / 2)) % MOD;
    if (b % 2 == 0) {
        return half;
    } else {
        return ((a % MOD) * half) % MOD;
    }
}

int main() {
    long long int n, k;
    cin >> n >> k;
    cout << binary_exponentiation(n, k) << "\n";
    // No need for return statement here
}
