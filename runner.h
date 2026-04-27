#pragma once
#include "lexer.h"
#include <iostream>
#include <vector>

struct PeekResult {
    bool sucess = false;
    Token value = Token("null token", U"");
};

PeekResult peek(std::vector<Token> vec, int position);
void run(std::vector<Token> tokens);