#include <iostream>
#include <vector>

using namespace std;

int maxKnowledge(int N, int M, const vector<int>& A, const vector<int>& B) {
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (A[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i - 1]] + B[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[N][M];
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }

    int max_knowledge = maxKnowledge(N, M, A, B);
    cout << max_knowledge << endl;

    return 0;
}
