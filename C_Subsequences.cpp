#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
public:
    FenwickTree(int size) : tree(size + 1, 0), size(size) {}

    void update(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += index & -index;
        }
    }

    long long query(int index) {
        long long sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

private:
    vector<long long> tree;
    int size;
};

int main() {
    int n, k;
    cin >> n >> k;
    if (n < k+1) {
        cout << 0;
        return 0;
    }
    vector<int> sequence(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> sequence[i];
    }

    vector<vector<long long>> dp(k + 2, vector<long long>(n + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = 1;
    }

    for (int length = 2; length <= k + 1; ++length) {
        FenwickTree fenwickTree(n);
        for (int i = 1; i <= n; ++i) {
            dp[length][i] = fenwickTree.query(sequence[i] - 1);
            fenwickTree.update(sequence[i], dp[length - 1][i]);
        }
    }

    long long result = 0;
    for (int i = 1; i <= n; ++i) {
        result += dp[k + 1][i];
    }

    cout << result << endl;

    return 0;
}
