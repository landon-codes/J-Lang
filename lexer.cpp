#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::string;
using std::vector;

class Token {
    public:
        string type;
        string value;

    Token(string tokenType, string tokenValue) {
        type = tokenType;
        value = tokenValue;
    }
};

int main() {
    Token test("testType", "testValue");

    cout << test.type << endl << test.value << endl;
    cout << u8"成功！";

    return 0;
}