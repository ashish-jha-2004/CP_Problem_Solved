#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000000 + 5;

int num_divisors[MAXN];

void compute_num_divisors() {
    // Initialize num_divisors array
    for (int i = 1; i < MAXN; ++i) {
        for (int j = i; j < MAXN; j += i) {
            num_divisors[j]++;
        }
    }
}

int main() {
    // Compute number of divisors for each number from 1 to 10^6
    compute_num_divisors();
    
    // Read input
    int n;
    cin >> n;
    
    while (n--) {
        int x;
        cin >> x;
        cout << num_divisors[x] << endl;
    }
    
    return 0;
}
