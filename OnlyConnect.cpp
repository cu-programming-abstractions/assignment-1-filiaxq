
#include "OnlyConnect.h"
#include "strlib.h"     // For toUpperCase
#include "cctype"       // For isalpha
    using namespace std;

bool isConsonant(char ch) {
    ch = toUpperCase(string(1, ch))[0]; // Convert to uppercase
    return isalpha(ch) && !(ch == 'A'  ch == 'E'  ch == 'I'  ch == 'O'  ch == 'U');
}

string onlyConnectize(string phrase) {
    if (phrase.empty()) return "";

    char first = toUpperCase(string(1, phrase[0]))[0];

    if (isConsonant(phrase[0])) {
        return string(1, first) + onlyConnectize(phrase.substr(1));
    } else {
        return onlyConnectize(phrase.substr(1));
    }
}







