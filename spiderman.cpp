#include "spiderman.hpp"
#include <curl/curl.h>
#include <iostream>

// callback util
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userdata) {
    userdata->append((char*)contents, size * nmemb);
    return size * nmemb;
}

spiderman::spiderman(const std::string& url) : url(url), html(" "){}

// fetch html content from a url
std::string spiderman::fetch() {
    CURL* curl = curl_easy_init();
    std::string response;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "CURL error: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    this->html = response;
    return response;
}

// tokenize the html content
std::vector<Token> spiderman::parse() {
    std::vector<Token> tokens;
    size_t pos = 0;
    while (pos < this->html.size()) {
        if (this->html[pos] == '<') {
            size_t endPos = this->html.find('>', pos);
            if (endPos != std::string::npos) {
                tokens.push_back({"TAG", html.substr(pos, endPos - pos + 1)});
                pos = endPos + 1;
            } else {
                break; // Malformed HTML
            }
        } else {
            size_t endPos = this->html.find('<', pos);
            tokens.push_back({"TEXT", this->html.substr(pos, endPos - pos)});
            pos = endPos;
        }
    }
    return tokens;
}
