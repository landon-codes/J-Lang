#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>

using namespace std;

// Change to use u32string for full character support
class Token {
    public:
        string type;
        u32string value; // Store as u32string internally

    Token(string tokenType, u32string tokenValue) {
        type = tokenType;
        value = tokenValue;
    }
};

string toUtf8(const u32string& u32str) {
    // Converts between UTF-32 (char32_t) and UTF-8 (char)
    wstring_convert<codecvt_utf8<char32_t>, char32_t> converter;
    return converter.to_bytes(u32str);
}


// Check for both ASCII and Wide-character whitespace
bool isWhitespace(char32_t c) {
    return c == U' ' || c == U'\t' || c == U'\n' || c == U'\r' || c == U'\u3000';
}

vector<Token> tokenize(const u32string& input) {
    vector<Token> tokens;
    size_t position = 0;
    const size_t length = input.length();

    while (position < length) {
        if (input[position] == U'「') {
            u32string buffer = U"";
            position++; // Skip opening 「

            while (position < length && input[position] != U'」') {
                buffer += input[position];
                position++;
            }

            if (position < length) position++; // Skip closing 」
            tokens.push_back(Token("string", buffer));
        } 
        else if (isWhitespace(input[position])) {
            position++;
        }
        else {
            position++; // Handle unknown characters to avoid infinite loops
        }
    }
    return tokens;
}

int main() {
    // Prefix with 'U' for UTF-32 literal
    u32string input = U"「世界よ、こんにちは！」";

    vector<Token> outputTokens = tokenize(input);

    for (const auto& token : outputTokens) {
        cout << "Type: " << token.type << endl;
        // Note: Printing u32string to cout requires conversion back to UTF-8
        // For simple debugging, we'll just acknowledge it worked:
        cout << toUtf8(token.value) << endl;
    }

    return 0;
}
