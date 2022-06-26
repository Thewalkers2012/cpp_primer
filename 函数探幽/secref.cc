// secref.cc -- defining and using a reference
#include <iostream>

int main() {
    using namespace std;

    int rats = 101;
    int &rodents = rats; // rodents is a reference

    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    int bunnies = 50;
    rodents = bunnies;
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "bunnies address = " << &bunnies;
    cout << ", rodents address = " << &rodents << endl;

    return 0;
}

/*
output:
    rats = 101, rodents = 101
    bunnies = 50, rats = 50, rodents = 50
    bunnies address = 0x7ff7b241916c, rodents address = 0x7ff7b2419178
*/