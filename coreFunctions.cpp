#inclede "lexer.h"
#include <iostream>

using namespace std;

// Prints text to the screen
void 示す(u32string text) {
    cout << toUtf8(text) << endl;
}