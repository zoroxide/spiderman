#include <bits/stdc++.h>
#include "../spiderman.hpp"

int main() {
    spiderman scraper("https://zoroxide.pages.dev");

    std::string content = scraper.fetch();
    std::vector<Token> tokens = scraper.parse();

    if (!content.empty()) {
        for (const auto& token : tokens) {
            if(token.type == "TEXT" && token.value == "Loay Mohamed") {
                std::cout << token.value << std::endl;
            }
        }
    } else {
        std::cerr << "Failed to fetch content from https://zoroxide.pages.dev" << std::endl;
    }

    return 0;
}
