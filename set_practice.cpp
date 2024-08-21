#include <iostream>
#include <set>

auto findLargestSmallerOrEqual(const std::multiset<int>& mset, int k) {
    auto it = mset.lower_bound(k); // Iterator pointing to the first element not less than k
    if (it == mset.begin()) {
        // k is less than or equal to the smallest element in the multiset
        return (*it == k) ? it : mset.end(); // Return the smallest element
    } 
    else {
        // k is between two elements in the multiset
        auto prevIt = std::prev(it);
        if (*it == k and it != mset.end()) return it;
        return (*prevIt < k) ? prevIt : it; // Return the largest element smaller than or equal to k
    }
}

int main() {
    std::multiset<int> mset = {2, 2, 4, 5, 5, 6, 6, 8};

    int k = 8, result = -1;
    if (findLargestSmallerOrEqual(mset, k) != mset.end())    
        result = *findLargestSmallerOrEqual(mset, k);
    std::cout << "Largest element smaller than or equal to " << k << ": " << result << std::endl;
    return 0;
}
