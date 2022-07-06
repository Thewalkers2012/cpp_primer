// stone.cc -- user-defined conversion functions
#include "stonewt.h"
#include <iostream>

int main() {
    using std::cout;

    StoneWt poppins(9, 2.8);
    double p_wt = poppins;

    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int(poppins) << " pounds.\n";

    return 0;
}

/*
output:
Convert to double => Poppins: 128.8 pounds.
Convert to int => Poppins: 129 pounds.
*/