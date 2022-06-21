// pointer.cc -- our first pointer variabel
#include <iostream>

int main() {
    using namespace std;

    int updates = 6;
    int *p_updates; // declare pointer to an int

    p_updates = &updates;

    // express values two ways
    cout << "Values: updates = " << updates;
    cout << ", *p_updates = " << *p_updates << endl;

    // use pointer to change value
    *p_updates = *p_updates + 1;
    cout << "New updates = " << updates << endl;

    return 0;
}
/*
output:
    Values: updates = 6, *p_updates = 6
    New updates = 7
*/