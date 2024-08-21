#include <iostream>
using namespace std;

#define MOD 1000000007
#define int long long

int binary_exponentiation(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a % MOD;
    }
    cerr<<"HEllo" << endl;
    int half = (binary_exponentiation(a, b / 2));
    half = (half * half) % MOD;
    if (b % 2 == 0) {
        return half;
    } else {
        return ((a % MOD) * half) % MOD;
    }
}

main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
  	cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    cout << binary_exponentiation(n, k) << "\n";
}
