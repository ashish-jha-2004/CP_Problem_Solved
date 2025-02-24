#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
// Sieve to generate all primes up to MAX.
vector<int> sievePrimes(int MAX) {
    vector<bool> isPrime(MAX+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= MAX; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    // The maximum n among test cases is at most 2e5.
    const int MAXVAL = 200000;
    vector<int> primes = sievePrimes(MAXVAL);
 
    while(t--){
        int n;
        cin >> n;
        // Build frequency array for numbers 0..n.
        // (We only care about numbers 2..n since a[i] are in [2,n].)
        vector<long long> freq(n+1, 0);
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(x <= n) {
                freq[x]++;
            }
        }
 
        long long ans = 0;
 
        // --- Case 1: semiprime of the form p^2 ---
        // For each prime p with p^2 <= n, the candidate values are p and p^2.
        for (int p : primes) {
            if ((long long)p * p > n) break;
            long long countPrime = freq[p];      // frequency of p
            long long countP2    = freq[(long long)p * p]; // frequency of p^2
            // Valid pairs: (p, p^2) and (p^2, p^2)
            ans += countPrime * countP2;
            ans += countP2 * (countP2 + 1LL) / 2;
        }
 
        // --- Case 2: semiprime of the form p*q with p < q ---
        int numPrimes = primes.size();
        for (int i = 0; i < numPrimes; i++){
            int p = primes[i];
            if(p > n) break; // p must be at most n
            for (int j = i + 1; j < numPrimes; j++){
                int q = primes[j];
                if ((long long)p * q > n) break; // p*q must be at most n to possibly appear in the array.
                long long countP = freq[p];
                long long countQ = freq[q];
                long long countPQ = freq[(long long)p * q]; // frequency of (p*q)
                // Valid pairs:
                // (p, q): contributes countP * countQ.
                // (p, p*q): contributes countP * countPQ.
                // (q, p*q): contributes countQ * countPQ.
                // (p*q, p*q): contributes countPQ*(countPQ+1)/2.
                ans += countP * countQ;
                ans += countP * countPQ;
                ans += countQ * countPQ;
                ans += countPQ * (countPQ + 1LL) / 2;
            }
        }
 
        cout << ans << "\n";
    }
    return 0;
}
