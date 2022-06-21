// init_ptr.cc -- initialize a pointer
#include <iostream>

int main() {
    using namespace std;

    int higgens = 5;
    int *pt = &higgens;

    cout << "Value of higgens = " << higgens
        << "; Address of higgens = " << &higgens << endl;

    cout << "Value of *pt = " << *pt
        << "; Value of pt = " << pt << endl;

    return 0;
}

/*
output:
    Value of higgens = 5; Address of higgens = 0x7ff7b4974178
    Value of *pt = 5; Value of pt = 0x7ff7b4974178
*/