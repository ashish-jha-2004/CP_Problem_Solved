#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long y, x;
        cin >> y >> x;

        long long n = max(y, x);
        long long result;

        if (n % 2 == 0) {
            if (y == n) {
                result = n * n - (x - 1);
            } else {
                result = (n - 1) * (n - 1) + y;
            }
        } else {
            if (x == n) {
                result = n * n - (y - 1);
            } else {
                result = (n - 1) * (n - 1) + x;
            }
        }

        cout << result << endl;
    }

    return 0;
}
