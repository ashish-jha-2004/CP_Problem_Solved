#include <bits/stdc++.h>
using namespace std;

// Function to perform the extended Euclidean algorithm
// Returns gcd and updates x and y to be the coefficients of a and b
long long extendedGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long x0, y0;
    long long gcd = extendedGCD(a, b, x0, y0);

    if (c % gcd != 0) {
        cout << "No\n";
        return;
    }

    // Scale the initial solution to get one particular solution for the equation a*x + b*y = c
    long long factor = c / gcd;
    x0 *= factor;
    y0 *= factor;

    long long k1 = b / gcd;
    long long k2 = a / gcd;

    // Adjust x0 and y0 to be non-negative
    long long t_min = ceil(-1.0 * x0 / k1);
    long long t_max = floor(1.0 * y0 / k2);

    if (t_min <= t_max) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;  // Number of test cases; assuming 1 by default
    while (t--) {
        solve();
    }
    return 0;
}
