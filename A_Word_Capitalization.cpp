#include <iostream>
#include <string>

int main() {
    std::string word;
    
    // Read the input word
    std::cin >> word;
    
    // Capitalize the first letter if the word is not empty
    if (!word.empty()) {
        word[0] = std::toupper(word[0]);
    }
    
    // Print the result
    std::cout << word << std::endl;
    
    return 0;
}