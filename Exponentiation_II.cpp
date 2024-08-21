#include <iostream>
using namespace std;

const int MOD = 1000000007;

// Function to compute x^y % m using modular exponentiation
long long power_mod(long long x, long long y, int m) {
    if (y == 0) return 1; // Base case: x^0 = 1
    long long result = 1;
    x = x % m; // Take modulo of base in case it's larger than m
    while (y > 0) {
        if (y % 2 == 1) { // If y is odd, multiply x with result
            result = (result * x) % m;
        }
        y = y >> 1; // Divide y by 2
        x = (x * x) % m; // Square x and take modulo
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        // Edge case: 0^0 = 1
        if (a == 0 && b == 0 && c == 0) {
            cout << 0 << endl;
            continue;
        }
        
        // Compute b^c % (MOD - 1) using modular exponentiation
        long long exp = power_mod(b, c, MOD - 1);
        
        // Compute a^(b^c) % MOD using modular exponentiation
        long long result = power_mod(a, exp, MOD);
        
        cout << result << endl;
    }
    
    return 0;
}
