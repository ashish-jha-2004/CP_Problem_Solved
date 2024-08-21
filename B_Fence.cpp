#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    
    // Calculate the sum of the first window of size k
    int current_sum = 0;
    for (int i = 0; i < k; ++i) {
        current_sum += h[i];
    }
    
    // Initialize variables for tracking the minimum sum and its starting index
    int min_sum = current_sum;
    int min_index = 0;
    
    // Slide the window across the array
    for (int i = k; i < n; ++i) {
        current_sum += h[i] - h[i - k]; // slide the window
        if (current_sum < min_sum) {
            min_sum = current_sum;
            min_index = i - k + 1;
        }
    }
    
    // Output the 1-based index of the start of the minimal sum segment
    cout << min_index + 1 << endl;
    
    return 0;
}
