#include <iostream>
#include <vector>
#include <algorithm>

int smallestSumCannotCreate(std::vector<int>& coins) {
    // Sort the coins in ascending order
    std::sort(coins.begin(), coins.end());

    // Initialize the smallest sum
    int smallest_sum = 1;

    // Iterate through the coins
    for (int coin : coins) {
        // If the current coin value is greater than the smallest_sum, break the loop
        if (coin > smallest_sum) {
            break;
        }
        // Otherwise, update smallest_sum
        smallest_sum += coin;
    }

    return smallest_sum;
}

int main() {
    std::vector<int> coins = {1, 2, 2, 7, 9};
    std::cout << "Smallest sum cannot be created: " << smallestSumCannotCreate(coins) << std::endl;

    return 0;
}
