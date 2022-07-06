// stone.cc -- user-defined conversion
#include "stonewt.h"
#include <iostream>

using std::cout;

void display(const StoneWt &st, int n);

int main() {
    StoneWt pavarotti = 260; // uses constructor to initialize
    StoneWt wolfe(285.7);
    StoneWt taft(21, 8);

    cout << "The tenor weiged ";
    pavarotti.show_stn();
    cout << "The detective weighed ";
    wolfe.show_stn();
    cout << "The President weighed ";
    taft.show_lbs();

    pavarotti = 265.8;
    taft = 325;

    cout << "After dinner, the president weighed ";
    taft.show_lbs();
    display(taft, 2);
    cout << "The wrestler weighed even more.\n";
    display(422, 2);
    cout << "No stone left unearned\n";


    return 0;
}

void display(const StoneWt &st, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Wow! ";
        st.show_stn();
    }
}

/*
The tenor weiged 18 stone, 8 pounds
The detective weighed 20 stone, 5 pounds
The President weighed 302 pounds
After dinner, the president weighed 325 pounds
Wow! 23 stone, 3 pounds
Wow! 23 stone, 3 pounds
The wrestler weighed even more.
Wow! 30 stone, 2 pounds
Wow! 30 stone, 2 pounds

*/