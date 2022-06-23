// strgback.cc -- a function that returns a pointer to char
#include <iostream>

char *buildstr(char ch, int n); // proto type

int main() {
    using namespace std;

    int times;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    cout << "Enter an integer: ";
    cin >> times;

    char *ps = buildstr(ch, times);
    cout << ps << endl;
    delete []ps;

    ps = buildstr('+', 20);
    cout << ps << "-DONE-" << ps << endl;
    delete []ps;

    return 0;
}

// builds string made of n c characters
char* buildstr(char c, int n) {
    char *pstr = new char[n + 1];
    pstr[n] = '\0';

    while (n-- > 0) {
        pstr[n] = c;
    }

    return pstr;
}

/*
output:
    Enter a character: V
    Enter an integer: 46
    VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
    ++++++++++++++++++++-DONE-++++++++++++++++++++
*/