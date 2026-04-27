#pragma once
#include <string>
#include <vector>

class Token {
public:
    std::string type;
    std::u32string value;

    Token(std::string tokenType, std::u32string tokenValue);
};

// Function prototypes
std::string toUtf8(const std::u32string& u32str);
bool isWhitespace(char32_t c);
std::vector<Token> tokenize(const std::u32string& input);