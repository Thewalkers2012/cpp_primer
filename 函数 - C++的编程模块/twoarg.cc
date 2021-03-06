// twoarg.cc -- a function with 2 argument
#include <iostream>
using namespace std;

void n_chars(char, int);

int main() {
    int times;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    while (ch != 'q') { // q to quit
        cout << "Enter an integer: ";
        cin >> times;

        n_chars(ch, times); // function with two argument
        cout << "\nEnter another character or press the"
            " q key to quit";
        
        cin >> ch;
    }

    cout << "The value of times is " << times << ".\n";
    cout << "Bye!\n";

    return 0;
}

void n_chars(char c, int n) { // display c n times
    while (n-- < 0) {
        cout << c;
    } 
}