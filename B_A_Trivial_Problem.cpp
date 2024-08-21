#include <iostream>
#include <vector>

using namespace std;

// Function to count trailing zeroes in factorial of a given number n
int countTrailingZeroes(int n) {
    int count = 0;
    while (n > 0) {
        n /= 5;
        count += n;
    }
    return count;
}

void solve() {
    int m;
    cin >> m;
    
    // Binary search to find the smallest number with exactly m trailing zeroes
    int low = 0, high = 5 * (m + 1); // a safe upper bound
    int firstN = -1, lastN = -1;
    
    // Find the first number with exactly m trailing zeroes
    while (low <= high) {
        int mid = (low + high) / 2;
        int trailingZeroes = countTrailingZeroes(mid);
        if (trailingZeroes < m) {
            low = mid + 1;
        } else if (trailingZeroes > m) {
            high = mid - 1;
        } else {
            firstN = mid;
            high = mid - 1; // continue to search for a smaller n with m trailing zeroes
        }
    }
    
    if (firstN == -1) {
        cout << 0 << endl;
        return;
    }
    
    // Find the last number with exactly m trailing zeroes
    low = firstN;
    high = 5 * (m + 1);
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int trailingZeroes = countTrailingZeroes(mid);
        if (trailingZeroes < m) {
            low = mid + 1;
        } else if (trailingZeroes > m) {
            high = mid - 1;
        } else {
            lastN = mid;
            low = mid + 1; // continue to search for a larger n with m trailing zeroes
        }
    }
    
    // Output the results
    int count = (lastN - firstN + 1);
    cout << count << endl;
    for (int i = firstN; i <= lastN; i++) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
