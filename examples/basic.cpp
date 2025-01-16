#include <bits/stdc++.h>
#include "../spiderman.hpp"

int main() {
    std::string url = "https://zoroxide.pages.dev";

    spiderman scraper(url);
    
    std::string content = scraper.fetch();
    std::vector<Token> tokens = scraper.parse();

    if (!content.empty()) {
        for (const auto& token : tokens) {
            std::cout << "Type: " << token.type << ", Value: " << token.value << std::endl;
        }
    } else {
        std::cerr << "Failed to fetch content from " << url << std::endl;
    }

    return 0;
}
