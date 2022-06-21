// numstr.cc -- following number input with line input
#include <iostream>

int main() {
    using namespace std;

    cout << "What year was your house built?\n";
    int year;
    cin >> year;

    cout << "What is its street address?\n";
    char address[80];
    cin.getline(address, 80);
    cout << "Your built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!" << endl;

    return 0;
}

/*
output:
    What year was your house built?
    1966
    What is its street address?
    Your built: 1966
    Address: 
    Done!
*/
