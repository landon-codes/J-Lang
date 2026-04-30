#include "runner.h"
#include "lexer.h"
#include <string>

using namespace std;

int main() {
    u32string input = U"「世界よ、こんにちは！」！示す";
    runProgram(tokenize(input));

    return 0;
}