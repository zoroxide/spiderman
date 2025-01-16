# Spiderman Web Scraper Framework

Spiderman is a lightweight C++ framework for web scraping. It allows you to fetch and parse HTML content from a given URL using `libcurl`. The parsed content is tokenized into `TAG` and `TEXT` tokens, providing a foundation for further processing.

## Features

- Fetch HTML content from a URL.
- Tokenize HTML into `TAG` and `TEXT` components.
- Simple and easy-to-use API.

## Requirements

- C++17 or later
- `libcurl`

## Installation
### *Windows support and test are comming soon :)*

1. Clone the repository:
   ```bash
   git clone https://github.com/zoroxide/spiderman.git
   cd spiderman
   ```

2. Install `libcurl` (if not already installed):
   ```bash
   # For Debian/Ubuntu
   sudo apt update && sudo apt install libcurl4-openssl-dev
   ```

3. Compile the code using a C++ compiler:
   ```bash
   g++ -std=c++17 -lcurl -o spiderman main.cpp spiderman.cpp
   ```

## Usage

### Example Code

```cpp
#include <bits/stdc++.h>
#include "spiderman.hpp"

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
```

### Token Structure

The `Token` structure represents the components of the parsed HTML:
```cpp
struct Token {
    std::string type;  // "TAG" or "TEXT"
    std::string value; // The HTML tag or text content
};
```

## File Structure

```
├── example.cpp       # Example usage
├── spiderman.hpp     # Header file
├── spiderman.cpp     # Implementation file
```

## Compilation

To compile the example:
```bash
g++ examples/{example}.cpp spiderman.cpp -o example -lcurl
sudo ./example
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contribution

Contributions are welcome! Please feel free to open issues or submit pull requests.

## Author

[Loay Mohamed](https://github.com/zoroxide)
