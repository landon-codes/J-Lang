#include "lexer.h"
#include "coreFunctions.h"
#include <iostream>
#include <vector>

using namespace std;

struct PeekResult {
    bool sucess = false;
    Token value = Token("null token", U"");
};

// Sees if there is a token after the current token
PeekResult peek(vector<Token> vec, int position) {
    PeekResult result;

    if (position + 1 < vec.size()) {
        result.value = vec[position+1];
        result.sucess = true;
    }

    return result;
}

void runProgram(vector<Token> tokens) {
    for (int position = 0; position < tokens.size(); position++) {
        if (tokens[position].type == "string") {
            u32string text = tokens[position].value;

            // Get the next token
            PeekResult after = peek(tokens, position);

            // Stop if no other tokens are found and throw warning
            if (!after.sucess) {
                cout << toUtf8(tokens[position].value) << U"は利用されていません。" << endl;
                
                break;
            }

            // Move to the next token
            position++;

            if (after.value.type == "function call operator") {
                PeekResult function = peek(tokens, position);

                // Throw error if no function is listed
                if (!function.sucess) {
                    cout << toUtf8(after.value.value) << U"後に関数は見つかりませんでした。" << endl;
                
                    break;
                }

                if (function.value.value == U"示す") {
                    示す(text);
                }
            }
        }
    }
}