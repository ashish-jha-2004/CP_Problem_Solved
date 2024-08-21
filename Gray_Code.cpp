#include <iostream>
#include <vector>

std::vector<int> generateGrayCode(int n) {
    std::vector<int> result;
    int totalNumbers = 1 << n;  // 2^n

    for (int i = 0; i < totalNumbers; ++i) {
        result.push_back(i ^ (i >> 1));
    }

    return result;
}

void printGrayCode(const std::vector<int>& grayCode, int n) {
    for (int num : grayCode) {
        for (int i = n - 1; i >= 0; --i) {
            std::cout << ((num >> i) & 1);
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> grayCode = generateGrayCode(n);
    printGrayCode(grayCode, n);

    return 0;
}
