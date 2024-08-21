#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 200000;

vector<long long> calculatePairs(int max_n) {
    vector<long long> primes;
    vector<bool> is_prime(max_n + 1, true);

    for (int i = 2; i <= max_n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= max_n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<unordered_map<long long, long long>> fact_prime_counts(max_n + 1);
    for (int i = 2; i <= max_n; ++i) {
        fact_prime_counts[i] = fact_prime_counts[i - 1];
        int num = i;
        for (auto p : primes) {
            if (p * p > num) break;
            while (num % p == 0) {
                fact_prime_counts[i][p]++;
                num /= p;
            }
        }
        if (num > 1) {
            fact_prime_counts[i][num]++;
        }
    }

    vector<long long> result(max_n + 1);
    for (int n = 1; n <= max_n; ++n) {
        long long divisors = 1;
        for (auto& [prime, count] : fact_prime_counts[n]) {
            divisors = (divisors * (2 * count + 1)) % MOD;
        }
        result[n] = (divisors + 1) / 2;
        result[n] %= MOD;
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    vector<int> queries(T);
    int max_n = 0;

    for (int i = 0; i < T; ++i) {
        cin >> queries[i];
        max_n = max(max_n, queries[i]);
    }

    vector<long long> result = calculatePairs(max_n);

    for (int i = 0; i < T; ++i) {
        cout << (2 * result[queries[i]] - 1 + MOD) % MOD << endl;
    }

    return 0;
}
