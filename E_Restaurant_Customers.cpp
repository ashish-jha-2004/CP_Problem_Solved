#include <bits/stdc++.h>
using namespace std;

int solve(const vector<vector<int>>& customers, int N) {
    vector<int> arr(N), dep(N);
    for (int i = 0; i < N; i++) {
        arr[i] = customers[i][0];
        dep[i] = customers[i][1];
    }

    // Sort the arrival and departure times
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0, j = 0;
    int currentCustomers = 0, maxCustomers = 0;
    while (i < N && j < N) {
        if (arr[i] < dep[j]) {
            currentCustomers++;
            maxCustomers = max(maxCustomers, currentCustomers);
            i++;
        } else {
            currentCustomers--;
            j++;
        }
    }
    return maxCustomers;
}

int main() {
    int N;
    cin >> N;

    if (N <= 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> customers(N, vector<int>(2));
    for (int i = 0; i < N; i++) {
        cin >> customers[i][0] >> customers[i][1];
    }

    cout << solve(customers, N) << endl;
    return 0;
}
