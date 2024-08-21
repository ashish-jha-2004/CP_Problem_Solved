#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
#define TEST_CASES int test_cases; cin >> test_cases
#define LOOP_TEST_CASES for (int t = 0; t < test_cases; ++t)
#define READ_INPUT(n, m) ull n, m; cin >> n >> m
#define OUTPUT_RESULT(result) cout << result << endl
#define WHILE(condition) while (condition)

int main() {
    TEST_CASES;
    LOOP_TEST_CASES {
        READ_INPUT(n, m);
        
        ull factor = 1;
        ull count = 0;
        ull result = 0;

        while (n > 0) {
            if (n & 1) {
                result += factor;
                count += factor;
            } 
            else {
                ull x = min(factor - count, count + 1);
                if (x <= m) {
                    result += factor;
                }
            }

            factor *= 2;
            n >>= 1;
        }

        while (factor - count <= m) {
            result += factor;
            factor *= 2;
        }

        OUTPUT_RESULT(result);
    }

    return 0;
}
