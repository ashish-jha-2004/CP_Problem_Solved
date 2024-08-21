#include <iostream>
#include <vector>
#include <algorithm>

long long smallestSumCannotCreate(std::vector<int>& coins) {
    std::sort(coins.begin(), coins.end());
    long long smallest_sum = 1;
    for (int coin : coins) {
        if (coin > smallest_sum) {
            break;
        }
        smallest_sum += coin;
    }
    return smallest_sum;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> coins;
    for (int i{0}; i<n; i++){
        int x;
        std::cin >> x;
        coins.push_back(x);
    }
    std::cout << smallestSumCannotCreate(coins) << std::endl;
    return 0;
}
