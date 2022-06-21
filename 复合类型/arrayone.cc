#include <iostream>

int main() {
    using namespace std;

    int yams[3];
    yams[0] = 7;
    yams[1] = 8;
    yams[2] = 6;

    int yamcosts[3] = {20, 30, 5};
    // NOTE: If your C++ compiler or translator can't initialize
    // this array, use static int yamcosts[3] = {20, 30, 5};

    cout << "Total yams = ";
    cout << yams[0] + yams[1] + yams[2] << endl;
    cout << "The package with " << yams[1] << " yams costs ";
    cout << yamcosts[1] << " cents per yam.\n";

    return 0;
}

/*
output:
    Total yams = 21
    The package with 8 yams costs 30 cents per yam.
*/