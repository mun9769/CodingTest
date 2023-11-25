#include <iostream>
#include <string>

using namespace std;

char toggleCase(char c) {
    if(c >= 'a' and c <= 'z') {
        int c2i = c - 'a';
        return c2i + 'A';
    }
    else {
        int c2i = c - 'A';
        return c2i + 'a';
    }
}

int main(void) {
    string str;
    cin >> str;
    for(char x: str) {
        cout << toggleCase(x);
    }
    return 0;
}