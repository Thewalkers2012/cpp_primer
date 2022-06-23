// strgfun.cc -- functions with a string argument
#include <iostream>

int c_in_str(const char* str, char ch);

int main() {
    using namespace std;
    char mmm[15] = "minimum"; // string in an array

    // some systems require preceding char with static to
    // enable array initialization

    char *wail = "ululate"; // wail points to string

    int ms = c_in_str(mmm, 'm');
    int us = c_in_str(wail, 'u');

    cout << ms << " m character in " << mmm << endl;
    cout << us << " u character in " << wail << endl;

    return 0;
}

// this function counts the number of ch character
// in the string str
int c_in_str(const char* str, char ch) {
    int count = 0;

    while (*str) {
        if (*str == ch) {
            count++;
        }
        str++;
    }

    return count;
}

/*
output:
    1 warning generated.
    3 m character in minimum
    2 u character in ululate
*/