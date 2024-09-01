#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> m(n);
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    int S = 0;
    for (int i = 0; i < k; ++i) {
        int c = 0;

        for (int j = i; j < n; j += k) {
            if (m[j] == 1) {
                c++;
            }
        }

        S += min(c, (n / k) - c);
    }

    cout << S << endl;

    return 0;
}
