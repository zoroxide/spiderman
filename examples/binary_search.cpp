#include <bits/stdc++.h>
#include "../spiderman.hpp"

int binarySearchToken(const std::vector<Token>& tokens, const std::string& target) {
    int left = 0;
    int right = tokens.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (tokens[mid].value == target) {
            return mid;
        } else if (tokens[mid].value < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    spiderman sp("https://zoroxide.pages.dev/");
    std::string content = sp.fetch();
    std::vector<Token> tokens = sp.parse();

    // Ensure tokens are sorted by value
    std::sort(tokens.begin(), tokens.end(), [](const Token& a, const Token& b) {
        return a.value < b.value;
    });

    std::string target = "Loay Mohamed";
    int found = binarySearchToken(tokens, target);

    if (found != -1) {
        std::cout << "Token with value '" << target << "' found. at index: " <<found<< std::endl;
    } else {
        std::cout << "Token with value '" << target << "' not found. and last index: " <<found<< std::endl;
    }

    return 0;
}

// g++ -o binary_search binary_search.cpp ../spiderman.cpp -lcurl
