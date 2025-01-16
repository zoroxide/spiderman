#include <string>
#include <vector>

struct Token {
    std::string type;
    std::string value;
};

class spiderman {
private:
    std::string url;
    std::string html;
    
public:
    spiderman(const std::string& url);
    std::vector<Token> parse();
    std::string fetch();
};