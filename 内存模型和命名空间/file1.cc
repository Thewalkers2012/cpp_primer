// file1.cc -- example of a three-file program
#include <iostream>
#include "coordin.h" // structure templates, function prototypes

using namespace std;

int main() {
    rect replace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> replace.x >> replace.y) { // slick use of cin
        pplace = rect_to_polar(replace);
        show_polar(pplace);

        cout << "Next two numbers(q to quit):";
    }
    cout << "Bye!\n";

    return 0;
}