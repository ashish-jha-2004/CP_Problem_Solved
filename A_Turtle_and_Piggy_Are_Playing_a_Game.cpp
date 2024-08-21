#include <iostream> 
using namespace std;

int nearest_power_of2(long long l, long long r) {
    long long ans1 = 0;
    for (int i{2}; i<=r; i *= 2) {
        ans1++;
    }
    return ans1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        cout << nearest_power_of2(n, m) << endl;
    }
    
}